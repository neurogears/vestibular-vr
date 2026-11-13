using Bonsai;
using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;

[Combinator]
[Description("")]
[WorkflowElementCategory(ElementCategory.Transform)]
public class ToPulseInterval
{
    public double ZeroThreshold {get; set;}
    public double MaxValue {get; set;}
    public double MinValue {get; set;}

    public IObservable<double> Process(IObservable<double> source)
    {
        return source.Select(value => {
            if (Math.Abs(value) < ZeroThreshold) {
                return 0.0;
            } else {
                var pulseInterval = 1.0/value;
                var clamp = Math.Max(Math.Min(pulseInterval, MaxValue), -MaxValue);
                if (Math.Abs(clamp) < MinValue) {
                    clamp = MinValue;
                }
                return clamp * 1000000;
            }
        });
    }
}
