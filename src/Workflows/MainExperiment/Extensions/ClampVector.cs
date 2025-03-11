using Bonsai;
using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using OpenTK;
using OpenTK.Input;

[Combinator]
[Description("")]
[WorkflowElementCategory(ElementCategory.Transform)]
public class ClampVector
{
    private Vector3 minVector;

    [TypeConverter(typeof(NumericRecordConverter))]
    public Vector3 MinVector {
        get {return minVector; }
        set {minVector = value;}
    }

    private Vector3 maxVector {get; set;}

    [TypeConverter(typeof(NumericRecordConverter))]
    public Vector3 MaxVector {
        get {return maxVector; }
        set {maxVector = value;}
    }

    public IObservable<Vector3> Process(IObservable<Vector3> source)
    {
        return source.Select(value => {
            return Vector3.Clamp(value, minVector, maxVector);
        });
    }
}
