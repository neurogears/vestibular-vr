using Bonsai;
using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;

[Combinator]
[Description("")]
[WorkflowElementCategory(ElementCategory.Transform)]
public class OverflowDifference
{
    private int rangeVal = short.MaxValue - short.MinValue;
    public IObservable<int> Process(IObservable<Tuple<short, short>> source)
    {
        return source.Select(value => {
            var d1 = value.Item2 - value.Item1;
            var d2 = (value.Item2 - value.Item1) + (Math.Sign(value.Item1 - value.Item2) * rangeVal);
            if (Math.Abs(d1) < Math.Abs(d2)) {
                return d1;
            } else {
                return d2;
            }
        });
    }
}
