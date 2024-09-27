using Bonsai;
using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;

public class WrapValue : Transform<int, int>
{
    public int MaxValue {get; set;}

    public override IObservable<int> Process(IObservable<int> source)
    {
        return source.Select(x => x >= 0 ? (x % MaxValue) : (MaxValue - Math.Abs(x % MaxValue)));
    }
}
