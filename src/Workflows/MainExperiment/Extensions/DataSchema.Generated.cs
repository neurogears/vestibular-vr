//----------------------
// <auto-generated>
//     Generated using the NJsonSchema v10.9.0.0 (Newtonsoft.Json v9.0.0.0) (http://NJsonSchema.org)
// </auto-generated>
//----------------------


namespace DataSchema
{
    #pragma warning disable // Disable all warnings

    [Bonsai.CombinatorAttribute()]
    [Bonsai.WorkflowElementCategoryAttribute(Bonsai.ElementCategory.Source)]
    public partial class Block
    {
    
        private string _alias = "unnamed";
    
        private StimulusProtocol _stimulus;
    
        private double _totalRuntime = 120D;
    
        private double _runThreshold = 100D;
    
        private double _decayTimestep = 0.1D;
    
        private double _runThresholdDecay = -1D;
    
        private double _haltProbability = 0D;
    
        private HaltProtocol _haltProtocol;
    
        private double _flowXToRunGain = 0D;
    
        private double _flowYToRunGain = 0D;
    
        private double _playbackToRunGain = 0D;
    
        private double _flowXToVisualGain = 0D;
    
        private double _flowYToVisualGain = 0D;
    
        private double _flowXToMotorGain = 0D;
    
        private double _flowYToMotorGain = 0D;
    
        private double _rotaryToVisualGain = 0D;
    
        private double _playbackToVisualGain = 0D;
    
        private double _playbackToMotorGain = 0D;
    
        private double _blockGainModifier = 1D;
    
        private string _playbackFilePath = "";
    
        /// <summary>
        /// The user-defined name of this block.
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="alias")]
        [System.ComponentModel.DescriptionAttribute("The user-defined name of this block.")]
        public string Alias
        {
            get
            {
                return _alias;
            }
            set
            {
                _alias = value;
            }
        }
    
        /// <summary>
        /// The visual stimulus to use
        /// </summary>
        [System.Xml.Serialization.XmlIgnoreAttribute()]
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="stimulus")]
        [System.ComponentModel.DescriptionAttribute("The visual stimulus to use")]
        public StimulusProtocol Stimulus
        {
            get
            {
                return _stimulus;
            }
            set
            {
                _stimulus = value;
            }
        }
    
        /// <summary>
        /// How long (in seconds) this block should run for
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="totalRuntime")]
        [System.ComponentModel.DescriptionAttribute("How long (in seconds) this block should run for")]
        public double TotalRuntime
        {
            get
            {
                return _totalRuntime;
            }
            set
            {
                _totalRuntime = value;
            }
        }
    
        /// <summary>
        /// The value (in position units) to reach before a halt decision is applied
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="runThreshold")]
        [System.ComponentModel.DescriptionAttribute("The value (in position units) to reach before a halt decision is applied")]
        public double RunThreshold
        {
            get
            {
                return _runThreshold;
            }
            set
            {
                _runThreshold = value;
            }
        }
    
        /// <summary>
        /// On each timestep (in seconds) the runThresholdDecay is applied
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="decayTimestep")]
        [System.ComponentModel.DescriptionAttribute("On each timestep (in seconds) the runThresholdDecay is applied")]
        public double DecayTimestep
        {
            get
            {
                return _decayTimestep;
            }
            set
            {
                _decayTimestep = value;
            }
        }
    
        /// <summary>
        /// Distance to threshold is decayed by this amount (in position units) per decayTimestep
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="runThresholdDecay")]
        [System.ComponentModel.DescriptionAttribute("Distance to threshold is decayed by this amount (in position units) per decayTime" +
            "step")]
        public double RunThresholdDecay
        {
            get
            {
                return _runThresholdDecay;
            }
            set
            {
                _runThresholdDecay = value;
            }
        }
    
        /// <summary>
        /// The probability that a halt decision is made after a running threshold has been reached
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="haltProbability")]
        [System.ComponentModel.DescriptionAttribute("The probability that a halt decision is made after a running threshold has been r" +
            "eached")]
        public double HaltProbability
        {
            get
            {
                return _haltProbability;
            }
            set
            {
                _haltProbability = value;
            }
        }
    
        /// <summary>
        /// The halt protocol to use on a positive halt decision
        /// </summary>
        [System.Xml.Serialization.XmlIgnoreAttribute()]
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="haltProtocol")]
        [System.ComponentModel.DescriptionAttribute("The halt protocol to use on a positive halt decision")]
        public HaltProtocol HaltProtocol
        {
            get
            {
                return _haltProtocol;
            }
            set
            {
                _haltProtocol = value;
            }
        }
    
        /// <summary>
        /// flow --> run distance traveled gain (X dimension)
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="flowXToRunGain")]
        [System.ComponentModel.DescriptionAttribute("flow --> run distance traveled gain (X dimension)")]
        public double FlowXToRunGain
        {
            get
            {
                return _flowXToRunGain;
            }
            set
            {
                _flowXToRunGain = value;
            }
        }
    
        /// <summary>
        /// flow --> run distance traveled gain (Y dimension)
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="flowYToRunGain")]
        [System.ComponentModel.DescriptionAttribute("flow --> run distance traveled gain (Y dimension)")]
        public double FlowYToRunGain
        {
            get
            {
                return _flowYToRunGain;
            }
            set
            {
                _flowYToRunGain = value;
            }
        }
    
        /// <summary>
        /// playback --> run distance traveled gain
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="playbackToRunGain")]
        [System.ComponentModel.DescriptionAttribute("playback --> run distance traveled gain")]
        public double PlaybackToRunGain
        {
            get
            {
                return _playbackToRunGain;
            }
            set
            {
                _playbackToRunGain = value;
            }
        }
    
        /// <summary>
        /// flow --> visual stimulus motion gain (X dimension)
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="flowXToVisualGain")]
        [System.ComponentModel.DescriptionAttribute("flow --> visual stimulus motion gain (X dimension)")]
        public double FlowXToVisualGain
        {
            get
            {
                return _flowXToVisualGain;
            }
            set
            {
                _flowXToVisualGain = value;
            }
        }
    
        /// <summary>
        /// flow --> visual stimulus motion gain (Y dimension)
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="flowYToVisualGain")]
        [System.ComponentModel.DescriptionAttribute("flow --> visual stimulus motion gain (Y dimension)")]
        public double FlowYToVisualGain
        {
            get
            {
                return _flowYToVisualGain;
            }
            set
            {
                _flowYToVisualGain = value;
            }
        }
    
        /// <summary>
        /// flow --> motor motion gain (X dimension)
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="flowXToMotorGain")]
        [System.ComponentModel.DescriptionAttribute("flow --> motor motion gain (X dimension)")]
        public double FlowXToMotorGain
        {
            get
            {
                return _flowXToMotorGain;
            }
            set
            {
                _flowXToMotorGain = value;
            }
        }
    
        /// <summary>
        /// flow --> motor motion gain (Y dimension)
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="flowYToMotorGain")]
        [System.ComponentModel.DescriptionAttribute("flow --> motor motion gain (Y dimension)")]
        public double FlowYToMotorGain
        {
            get
            {
                return _flowYToMotorGain;
            }
            set
            {
                _flowYToMotorGain = value;
            }
        }
    
        /// <summary>
        /// rotary --> visual stimulus motion gain
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="rotaryToVisualGain")]
        [System.ComponentModel.DescriptionAttribute("rotary --> visual stimulus motion gain")]
        public double RotaryToVisualGain
        {
            get
            {
                return _rotaryToVisualGain;
            }
            set
            {
                _rotaryToVisualGain = value;
            }
        }
    
        /// <summary>
        /// playback source --> visual stimulus motion gain
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="playbackToVisualGain")]
        [System.ComponentModel.DescriptionAttribute("playback source --> visual stimulus motion gain")]
        public double PlaybackToVisualGain
        {
            get
            {
                return _playbackToVisualGain;
            }
            set
            {
                _playbackToVisualGain = value;
            }
        }
    
        /// <summary>
        /// playback source --> motor motion gain
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="playbackToMotorGain")]
        [System.ComponentModel.DescriptionAttribute("playback source --> motor motion gain")]
        public double PlaybackToMotorGain
        {
            get
            {
                return _playbackToMotorGain;
            }
            set
            {
                _playbackToMotorGain = value;
            }
        }
    
        /// <summary>
        /// Block specific gain coefficient to apply
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="blockGainModifier")]
        [System.ComponentModel.DescriptionAttribute("Block specific gain coefficient to apply")]
        public double BlockGainModifier
        {
            get
            {
                return _blockGainModifier;
            }
            set
            {
                _blockGainModifier = value;
            }
        }
    
        /// <summary>
        /// Path to the playback file to be used in this block
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="playbackFilePath")]
        [System.ComponentModel.DescriptionAttribute("Path to the playback file to be used in this block")]
        public string PlaybackFilePath
        {
            get
            {
                return _playbackFilePath;
            }
            set
            {
                _playbackFilePath = value;
            }
        }
    
        public System.IObservable<Block> Process()
        {
            return System.Reactive.Linq.Observable.Defer(() => System.Reactive.Linq.Observable.Return(
                new Block
                {
                    Alias = _alias,
                    Stimulus = _stimulus,
                    TotalRuntime = _totalRuntime,
                    RunThreshold = _runThreshold,
                    DecayTimestep = _decayTimestep,
                    RunThresholdDecay = _runThresholdDecay,
                    HaltProbability = _haltProbability,
                    HaltProtocol = _haltProtocol,
                    FlowXToRunGain = _flowXToRunGain,
                    FlowYToRunGain = _flowYToRunGain,
                    PlaybackToRunGain = _playbackToRunGain,
                    FlowXToVisualGain = _flowXToVisualGain,
                    FlowYToVisualGain = _flowYToVisualGain,
                    FlowXToMotorGain = _flowXToMotorGain,
                    FlowYToMotorGain = _flowYToMotorGain,
                    RotaryToVisualGain = _rotaryToVisualGain,
                    PlaybackToVisualGain = _playbackToVisualGain,
                    PlaybackToMotorGain = _playbackToMotorGain,
                    BlockGainModifier = _blockGainModifier,
                    PlaybackFilePath = _playbackFilePath
                }));
        }
    }


    [Bonsai.CombinatorAttribute()]
    [Bonsai.WorkflowElementCategoryAttribute(Bonsai.ElementCategory.Source)]
    public partial class StimulusProtocol
    {
    
        private StimulusProtocolType _type = DataSchema.StimulusProtocolType.Grating;
    
        private double _spatialFrequency = 0.1D;
    
        private string _textureName = "";
    
        private double _offset1 = -90D;
    
        private double _extent1 = 180D;
    
        private double _offset2 = 90D;
    
        private double _extent2 = 180D;
    
        /// <summary>
        /// The type and parameters of the visual stimulus to use
        /// </summary>
        [System.Xml.Serialization.XmlIgnoreAttribute()]
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="type")]
        [System.ComponentModel.DescriptionAttribute("The type and parameters of the visual stimulus to use")]
        public StimulusProtocolType Type
        {
            get
            {
                return _type;
            }
            set
            {
                _type = value;
            }
        }
    
        /// <summary>
        /// Spatial frequency for stimuli where this is a parameter
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="spatialFrequency")]
        [System.ComponentModel.DescriptionAttribute("Spatial frequency for stimuli where this is a parameter")]
        public double SpatialFrequency
        {
            get
            {
                return _spatialFrequency;
            }
            set
            {
                _spatialFrequency = value;
            }
        }
    
        /// <summary>
        /// Name of texture resource to load if required
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="textureName")]
        [System.ComponentModel.DescriptionAttribute("Name of texture resource to load if required")]
        public string TextureName
        {
            get
            {
                return _textureName;
            }
            set
            {
                _textureName = value;
            }
        }
    
        /// <summary>
        /// Offset (in degrees) for primary visual stimulus
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="offset1")]
        [System.ComponentModel.DescriptionAttribute("Offset (in degrees) for primary visual stimulus")]
        public double Offset1
        {
            get
            {
                return _offset1;
            }
            set
            {
                _offset1 = value;
            }
        }
    
        /// <summary>
        /// X screen extent (in degrees) for primary visual stimulus
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="extent1")]
        [System.ComponentModel.DescriptionAttribute("X screen extent (in degrees) for primary visual stimulus")]
        public double Extent1
        {
            get
            {
                return _extent1;
            }
            set
            {
                _extent1 = value;
            }
        }
    
        /// <summary>
        /// Offset (in degrees) for secondary visual stimulus
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="offset2")]
        [System.ComponentModel.DescriptionAttribute("Offset (in degrees) for secondary visual stimulus")]
        public double Offset2
        {
            get
            {
                return _offset2;
            }
            set
            {
                _offset2 = value;
            }
        }
    
        /// <summary>
        /// X screen extent (in degrees) for secondary visual stimulus
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="extent2")]
        [System.ComponentModel.DescriptionAttribute("X screen extent (in degrees) for secondary visual stimulus")]
        public double Extent2
        {
            get
            {
                return _extent2;
            }
            set
            {
                _extent2 = value;
            }
        }
    
        public System.IObservable<StimulusProtocol> Process()
        {
            return System.Reactive.Linq.Observable.Defer(() => System.Reactive.Linq.Observable.Return(
                new StimulusProtocol
                {
                    Type = _type,
                    SpatialFrequency = _spatialFrequency,
                    TextureName = _textureName,
                    Offset1 = _offset1,
                    Extent1 = _extent1,
                    Offset2 = _offset2,
                    Extent2 = _extent2
                }));
        }
    }


    [Bonsai.CombinatorAttribute()]
    [Bonsai.WorkflowElementCategoryAttribute(Bonsai.ElementCategory.Source)]
    public partial class HaltProtocol
    {
    
        private double _minumumDelay = 0.1D;
    
        private double _randomDelay = 0.5D;
    
        private double _haltTime = 2D;
    
        private double _haltGain = 0D;
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="minumumDelay")]
        public double MinumumDelay
        {
            get
            {
                return _minumumDelay;
            }
            set
            {
                _minumumDelay = value;
            }
        }
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="randomDelay")]
        public double RandomDelay
        {
            get
            {
                return _randomDelay;
            }
            set
            {
                _randomDelay = value;
            }
        }
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="haltTime")]
        public double HaltTime
        {
            get
            {
                return _haltTime;
            }
            set
            {
                _haltTime = value;
            }
        }
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="haltGain")]
        public double HaltGain
        {
            get
            {
                return _haltGain;
            }
            set
            {
                _haltGain = value;
            }
        }
    
        public System.IObservable<HaltProtocol> Process()
        {
            return System.Reactive.Linq.Observable.Defer(() => System.Reactive.Linq.Observable.Return(
                new HaltProtocol
                {
                    MinumumDelay = _minumumDelay,
                    RandomDelay = _randomDelay,
                    HaltTime = _haltTime,
                    HaltGain = _haltGain
                }));
        }
    }


    [Bonsai.CombinatorAttribute()]
    [Bonsai.WorkflowElementCategoryAttribute(Bonsai.ElementCategory.Source)]
    public partial class VestibularVrSession
    {
    
        private Metadata _metadata;
    
        private System.Collections.Generic.List<Block> _blocks = new System.Collections.Generic.List<Block>();
    
        private MotorSettings _motorSettings;
    
        [System.Xml.Serialization.XmlIgnoreAttribute()]
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="metadata")]
        public Metadata Metadata
        {
            get
            {
                return _metadata;
            }
            set
            {
                _metadata = value;
            }
        }
    
        [System.Xml.Serialization.XmlIgnoreAttribute()]
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="blocks")]
        public System.Collections.Generic.List<Block> Blocks
        {
            get
            {
                return _blocks;
            }
            set
            {
                _blocks = value;
            }
        }
    
        [System.Xml.Serialization.XmlIgnoreAttribute()]
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="motorSettings")]
        public MotorSettings MotorSettings
        {
            get
            {
                return _motorSettings;
            }
            set
            {
                _motorSettings = value;
            }
        }
    
        public System.IObservable<VestibularVrSession> Process()
        {
            return System.Reactive.Linq.Observable.Defer(() => System.Reactive.Linq.Observable.Return(
                new VestibularVrSession
                {
                    Metadata = _metadata,
                    Blocks = _blocks,
                    MotorSettings = _motorSettings
                }));
        }
    }


    public enum StimulusProtocolType
    {
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="grating")]
        Grating = 0,
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="texture")]
        Texture = 1,
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="cloud")]
        Cloud = 2,
    }


    [Bonsai.CombinatorAttribute()]
    [Bonsai.WorkflowElementCategoryAttribute(Bonsai.ElementCategory.Source)]
    public partial class Metadata
    {
    
        private string _animalId = "";
    
        private string _rootPath = "";
    
        private double _runGain = 1D;
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="animalId")]
        public string AnimalId
        {
            get
            {
                return _animalId;
            }
            set
            {
                _animalId = value;
            }
        }
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="rootPath")]
        public string RootPath
        {
            get
            {
                return _rootPath;
            }
            set
            {
                _rootPath = value;
            }
        }
    
        /// <summary>
        /// Coefficient applied to movement delta (e.g. from flow sensor) to calculate running speed in visual environment.
        /// </summary>
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="runGain")]
        [System.ComponentModel.DescriptionAttribute("Coefficient applied to movement delta (e.g. from flow sensor) to calculate runnin" +
            "g speed in visual environment.")]
        public double RunGain
        {
            get
            {
                return _runGain;
            }
            set
            {
                _runGain = value;
            }
        }
    
        public System.IObservable<Metadata> Process()
        {
            return System.Reactive.Linq.Observable.Defer(() => System.Reactive.Linq.Observable.Return(
                new Metadata
                {
                    AnimalId = _animalId,
                    RootPath = _rootPath,
                    RunGain = _runGain
                }));
        }
    }


    [Bonsai.CombinatorAttribute()]
    [Bonsai.WorkflowElementCategoryAttribute(Bonsai.ElementCategory.Source)]
    public partial class MotorSettings
    {
    
        private int _nominalPulseInterval = 200;
    
        private int _initialPulseInterval = 200;
    
        private int _pulseStepInterval = 2;
    
        private int _pulsePeriod = 10;
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="nominalPulseInterval")]
        public int NominalPulseInterval
        {
            get
            {
                return _nominalPulseInterval;
            }
            set
            {
                _nominalPulseInterval = value;
            }
        }
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="initialPulseInterval")]
        public int InitialPulseInterval
        {
            get
            {
                return _initialPulseInterval;
            }
            set
            {
                _initialPulseInterval = value;
            }
        }
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="pulseStepInterval")]
        public int PulseStepInterval
        {
            get
            {
                return _pulseStepInterval;
            }
            set
            {
                _pulseStepInterval = value;
            }
        }
    
        [YamlDotNet.Serialization.YamlMemberAttribute(Alias="pulsePeriod")]
        public int PulsePeriod
        {
            get
            {
                return _pulsePeriod;
            }
            set
            {
                _pulsePeriod = value;
            }
        }
    
        public System.IObservable<MotorSettings> Process()
        {
            return System.Reactive.Linq.Observable.Defer(() => System.Reactive.Linq.Observable.Return(
                new MotorSettings
                {
                    NominalPulseInterval = _nominalPulseInterval,
                    InitialPulseInterval = _initialPulseInterval,
                    PulseStepInterval = _pulseStepInterval,
                    PulsePeriod = _pulsePeriod
                }));
        }
    }


    /// <summary>
    /// Serializes a sequence of data model objects into YAML strings.
    /// </summary>
    [Bonsai.CombinatorAttribute()]
    [Bonsai.WorkflowElementCategoryAttribute(Bonsai.ElementCategory.Transform)]
    [System.ComponentModel.DescriptionAttribute("Serializes a sequence of data model objects into YAML strings.")]
    public partial class SerializeToYaml
    {
    
        private System.IObservable<string> Process<T>(System.IObservable<T> source)
        {
            return System.Reactive.Linq.Observable.Defer(() =>
            {
                var serializer = new YamlDotNet.Serialization.SerializerBuilder().Build();
                return System.Reactive.Linq.Observable.Select(source, value => serializer.Serialize(value)); 
            });
        }

        public System.IObservable<string> Process(System.IObservable<Block> source)
        {
            return Process<Block>(source);
        }

        public System.IObservable<string> Process(System.IObservable<StimulusProtocol> source)
        {
            return Process<StimulusProtocol>(source);
        }

        public System.IObservable<string> Process(System.IObservable<HaltProtocol> source)
        {
            return Process<HaltProtocol>(source);
        }

        public System.IObservable<string> Process(System.IObservable<VestibularVrSession> source)
        {
            return Process<VestibularVrSession>(source);
        }

        public System.IObservable<string> Process(System.IObservable<Metadata> source)
        {
            return Process<Metadata>(source);
        }

        public System.IObservable<string> Process(System.IObservable<MotorSettings> source)
        {
            return Process<MotorSettings>(source);
        }
    }


    /// <summary>
    /// Deserializes a sequence of YAML strings into data model objects.
    /// </summary>
    [System.ComponentModel.DefaultPropertyAttribute("Type")]
    [Bonsai.WorkflowElementCategoryAttribute(Bonsai.ElementCategory.Transform)]
    [System.Xml.Serialization.XmlIncludeAttribute(typeof(Bonsai.Expressions.TypeMapping<Block>))]
    [System.Xml.Serialization.XmlIncludeAttribute(typeof(Bonsai.Expressions.TypeMapping<StimulusProtocol>))]
    [System.Xml.Serialization.XmlIncludeAttribute(typeof(Bonsai.Expressions.TypeMapping<HaltProtocol>))]
    [System.Xml.Serialization.XmlIncludeAttribute(typeof(Bonsai.Expressions.TypeMapping<VestibularVrSession>))]
    [System.Xml.Serialization.XmlIncludeAttribute(typeof(Bonsai.Expressions.TypeMapping<Metadata>))]
    [System.Xml.Serialization.XmlIncludeAttribute(typeof(Bonsai.Expressions.TypeMapping<MotorSettings>))]
    [System.ComponentModel.DescriptionAttribute("Deserializes a sequence of YAML strings into data model objects.")]
    public partial class DeserializeFromYaml : Bonsai.Expressions.SingleArgumentExpressionBuilder
    {
    
        public DeserializeFromYaml()
        {
            Type = new Bonsai.Expressions.TypeMapping<VestibularVrSession>();
        }

        public Bonsai.Expressions.TypeMapping Type { get; set; }

        public override System.Linq.Expressions.Expression Build(System.Collections.Generic.IEnumerable<System.Linq.Expressions.Expression> arguments)
        {
            var typeMapping = (Bonsai.Expressions.TypeMapping)Type;
            var returnType = typeMapping.GetType().GetGenericArguments()[0];
            return System.Linq.Expressions.Expression.Call(
                typeof(DeserializeFromYaml),
                "Process",
                new System.Type[] { returnType },
                System.Linq.Enumerable.Single(arguments));
        }

        private static System.IObservable<T> Process<T>(System.IObservable<string> source)
        {
            return System.Reactive.Linq.Observable.Defer(() =>
            {
                var serializer = new YamlDotNet.Serialization.DeserializerBuilder().Build();
                return System.Reactive.Linq.Observable.Select(source, value =>
                {
                    var reader = new System.IO.StringReader(value);
                    var parser = new YamlDotNet.Core.MergingParser(new YamlDotNet.Core.Parser(reader));
                    return serializer.Deserialize<T>(parser);
                });
            });
        }
    }
}