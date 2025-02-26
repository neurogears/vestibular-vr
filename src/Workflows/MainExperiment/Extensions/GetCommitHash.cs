using Bonsai;
using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using LibGit2Sharp;

[Combinator]
[Description("")]
[WorkflowElementCategory(ElementCategory.Transform)]
public class GetCommitHash
{
    public IObservable<string> Process(IObservable<IRepository> source)
    {
        return source.Select(repo => {
            return repo.Head.Tip.Sha;
        });
    }
}
