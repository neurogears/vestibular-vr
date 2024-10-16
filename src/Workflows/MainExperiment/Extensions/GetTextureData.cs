using Bonsai;
using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using Bonsai.Shaders;

public class GetTextureData : Source<TextureSequence>
{
    [TypeConverter(typeof(TextureNameConverter))]
    public string TextureName { get; set; }
    
    public override IObservable<TextureSequence> Generate()
    {
        return ShaderManager.WindowSource.Select(window => {
            var textureSequence = window.ResourceManager.Load<Texture>(TextureName) as TextureSequence;
            return textureSequence;
        });
    }
}
