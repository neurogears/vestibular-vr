using AxNstSquiggleCtrlLib;
using Bonsai;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive;
using System.Reactive.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BonsaiNewScale
{
    public class NewScaleControl : Combinator<double, double>
    {
        public override IObservable<double> Process(IObservable<double> source)
        {
            return Observable.Create<double>((observer, cancellationToken) =>
            {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);

                var ax = new SquiggleContext();
                return Task.Factory.StartNew(() =>
                {
                    var axThread = new Thread(t =>
                    {
                        ax.Control = new AxNstSquiggleCtrl();
                        ax.Form = new Form
                        {
                            Controls = { ax.Control }
                        };
                        ax.Form.Load += (sender, e) =>
                        {
                            ax.Control.Initialize();
                            ax.Control.Connect();

                            var sourceObserver = Observer.Create<double>(val => { ax.Control.MoveAbsolute(0, val); });
                            var dispose = source.Subscribe(sourceObserver);

                            Task.Factory.StartNew(() =>
                            {
                                while (!cancellationToken.IsCancellationRequested)
                                {
                                    ax.Control.QueryPosStatus(0);
                                    observer.OnNext(ax.Control.get_Position(0));
                                }
                            }).ContinueWith(x => ax.Form.Invoke((MethodInvoker)delegate
                            {
                                sourceObserver.OnCompleted();
                                dispose.Dispose();

                                ax.Form.Close();
                                ax.Control.Disconnect();
                                ax.Control.Dispose();
                            }));
                        };

                        ax.Form.ShowDialog();
                    });
                    axThread.SetApartmentState(ApartmentState.STA);
                    axThread.Start();

                    Application.Run();
                });
            });
        }
    }

    struct SquiggleContext
    {
        public AxNstSquiggleCtrl Control;
        public Form Form;
    }
}
