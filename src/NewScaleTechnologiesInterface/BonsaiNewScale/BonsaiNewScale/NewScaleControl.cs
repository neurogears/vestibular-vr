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
                        ax.ctrl = new AxNstSquiggleCtrl();
                        ax.form = new Form
                        {
                            Controls = { ax.ctrl }
                        };
                        ax.form.Load += (sender, e) =>
                        {
                            ax.ctrl.Initialize();
                            ax.ctrl.Connect();

                            var sourceObserver = Observer.Create<double>(val => { ax.ctrl.MoveAbsolute(0, val); });
                            var dispose = source.Subscribe(sourceObserver);

                            Task.Factory.StartNew(() =>
                            {
                                while (!cancellationToken.IsCancellationRequested)
                                {
                                    ax.ctrl.QueryPosStatus(0);
                                    observer.OnNext(ax.ctrl.get_Position(0));
                                }
                            }).ContinueWith(x => ax.form.Invoke((MethodInvoker)delegate
                            {
                                sourceObserver.OnCompleted();
                                dispose.Dispose();

                                ax.form.Close();
                                ax.ctrl.Disconnect();
                                ax.ctrl.Dispose();
                            }));
                        };

                        ax.form.ShowDialog();
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
        public AxNstSquiggleCtrl ctrl;
        public Form form;
    }
}
