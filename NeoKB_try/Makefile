VPATH=Base:Base/Config:Base/Graphic:Base/Graphic/Map:Base/Graphic/Renderer:Base/Play:Base/Ruleset:\
Base/Scheduler:Base/Scheduler/Event:Base/Scheduler/Event/ControlPoints:Base/Scheduler/Event/Effect:\
Base/Scheduler/Event/Effect/Algorithm:\
Base/Sheetmusic:Base/Sheetmusic/Format:Base/Sheetmusic/IO:Base/Sheetmusic/Pattern:\
Devices:Devices/Graphic/Renderers:Devices/LedDriver:\
RulesetMeteor:RulesetMeteor/Config:RulesetMeteor/Graphic:RulesetMeteor/Graphic/Renderer:\
RulesetMeteor/Play:RulesetMeteor/Scheduler/Event/Effect:RulesetMeteor/Scheduler/Event/Effect/Algorithm:\
RulesetMeteor/Sheetmusic:RulesetMeteor/Sheetmusic/Pattern:\
Util:Util/Hierachal:Util/Update

INCLUDE =  

#INCLUDE = -IBase -IBase/Config -IBase/Graphic -IBase/Graphic/Map -IBase/Graphic/Renderer -IBase/Play:Base/Ruleset \
#-IBase/Scheduler -IBase/Scheduler/Event -IBase/Scheduler/Event/ControlPoints -IBase/Scheduler/Event/Effect \
#-IRulesetMeteor -IRulesetMeteor/Config -IRulesetMeteor/Graphic -IRulesetMeteor/Graphic/Renderer \
#-IRulesetMeteor/Play -IRulesetMeteor/Scheduler/Event/Effect -IRulesetMeteor/Scheduler/Event/Effect/Algorithm \
#-IRulesetMeteor/Sheetmusic -IRulesetMeteor/Sheetmusic/Pattern \
#-IUtil -IUtil/Hierachal -IUtil/Update

#INCLUDE = -IBase -IBase/Config -IBase/Graphic -I./Base/Graphic/Map -I./Base/Graphic/Renderer -I./Base/Play:Base/Ruleset \
#-I./Base/Scheduler -I./Base/Scheduler/Event -I./Base/Scheduler/Event/ControlPoints -I./Base/Scheduler/Event/Effect \
#-I./RulesetMeteor -I./RulesetMeteor/Config -I./RulesetMeteor/Graphic -I./RulesetMeteor/Graphic/Renderer \
#-I./RulesetMeteor/Play -I./RulesetMeteor/Scheduler/Event/Effect -I./RulesetMeteor/Scheduler/Event/Effect/Algorithm \
#-I./RulesetMeteor/Sheetmusic -I./RulesetMeteor/Sheetmusic/Pattern \
#-I./Util -I./Util/Hierachal -I./Util/Update


TARGET  = MeteoKB
#compiler 
CC = g++
#cflags 
CFLAGS = -Wall -ansi -s -std=c++14
#object 
OBJS = Program.o Game.o \
ConfigManager.o FrameworkConfigManager.o \
Map.o renderer.o \
Player.o Playfield.o Session.o Ruleset.o RulesetExecutor.o RulesetInfo.o \
Scheduler.o Event.o EventProcessor.o EventProcessorMaster.o ControlPoint.o NoteControlPoint.o Effect.o EffectMapper.o MapAlgorithm.o MapGenerateAlgorithm.o MapShiftAlgorithm.o \
Sheetmusic.o SheetmusicConverter.o SheetmusicManager.o SheetmusicMetadata.o SheetmusicPostprocesser.o SheetmusicPostprocessor.o WorkingSheetmusic.o \
SmDecoder.o SimpleSmDecoder.o FileReader.o Pattern.o PatternGenerator.o \
WS2812v10Renderer.o dma.o pwm.o ws2811.o mailbox.o pcm.o rpihw.o \
MeteorGame.o MeteorConfigManager.o MeteorPlayfield.o MeteorRuleset.o MeteorRulesetExecutor.o \
ExplodeEffect.o ExplodeEffectMapper.o FallEffect.o FallEffectMapper.o GlowLineEffect.o GlowLineEffectMapper.o \
ExplodeMapAlgorithm.o FallMapAlgorithm.o GlowLineMapAlgorithm.o \
MeteorSheetmusicConverter.o MeteorPatternGenerator.o \
FileSystem.o InstanceCreator.o MtoObject.o ProgramInitializer.o \
Cachable.o ChildAddable.o HasParent.o Loadable.o LoadStateHandler.o



all:$(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(OBJS) -o $@ 
	
.c.o:
	$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $< 	
	
.cpp.o:
	$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f *.o $(TARGET)