using Bonsai;
using System.ComponentModel;
using System.Collections.Generic;
using Bonsai.Resources;
using System.IO;
using Bonsai.Shaders.Configuration;

[Combinator]
[Description("Creates a collection of textures from the specified image folder.")]
[WorkflowElementCategory(ElementCategory.Combinator)]
public class TextureFolder : ResourceLoader
{
    [Description("The path to search.")]
    [Editor("Bonsai.Design.FolderNameEditor, Bonsai.Design", DesignTypes.UITypeEditor)]
    public string Path { get; set; }

    protected override IEnumerable<IResourceConfiguration> GetResources()
    {
        foreach (var entry in Directory.EnumerateFiles(Path))
        {
            yield return new ImageSequence
            {
                Name = System.IO.Path.GetFileNameWithoutExtension(entry),
                FileName = entry
            };
        }
    }
}
