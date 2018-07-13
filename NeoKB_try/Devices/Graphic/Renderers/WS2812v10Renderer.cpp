#include "WS2812v10Renderer.h"

#include <cstring>


// defaults for cmdline options
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                10
#define DMA                     10
//#define STRIP_TYPE            WS2811_STRIP_RGB		// WS2812/SK6812RGB integrated chip+leds
#define STRIP_TYPE              WS2811_STRIP_GBR		// WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE            SK6812_STRIP_RGBW		// SK6812RGBW (NOT SK6812RGB)

using namespace Devices::Graphics::Renderers;


int WS2812v10Renderer::load()
{
	FrameworkConfigManager* f = GetCache<FrameworkConfigManager>("FrameworkConfigManager");
	if (!f)
		throw runtime_error("int WS2812v10Renderer::load() : Framework Config Manager not found in cache.");
	return load(f);
}

int WS2812v10Renderer::load(FrameworkConfigManager * f)
{
	if (f->Get<int>(FrameworkSetting::Width, &width)) {}
	if (f->Get<int>(FrameworkSetting::StartPitch, &startPitch)) {}
	if (f->Get<int>(FrameworkSetting::Height, &height)) {}
	if (f->Get<int>(FrameworkSetting::BlackKeyHeight, &blackKeyHeight)) {}

	
	int arraySize = 0;

	for (int i = 0; i < width; i++) {

		bool whiteKey = isWhiteKey(startPitch + i);

		arraySize += whiteKey ? height : blackKeyHeight;

	}
	
	lightArray.freq = TARGET_FREQ;
	lightArray.dmanum = DMA;
	lightArray.channel[0].gpionum = GPIO_PIN;
	lightArray.channel[0].count = arraySize;
	lightArray.channel[0].invert = 0;
	lightArray.channel[0].brightness = 0;
	lightArray.channel[0].strip_type = STRIP_TYPE;
	lightArray.channel[1].gpionum = 0;
	lightArray.channel[1].count = 0;
	lightArray.channel[1].invert = 0;
	lightArray.channel[1].brightness = 0;

	ws2811_return_t ret;
	if ((ret = ws2811_init(&lightArray)) != WS2811_SUCCESS)
	{
		fprintf(stderr, "ws2811_init failed: %s\n", ws2811_get_return_t_str(ret));
		//return ret;
		// TODO: 噴錯誤
	}

	return 0;
}

WS2812v10Renderer::WS2812v10Renderer(): Renderer(), RegisterType("WS2812v10Renderer")
{
	registerLoad(bind(static_cast<int(WS2812v10Renderer::*)(void)>(&WS2812v10Renderer::load), this));
}

int WS2812v10Renderer::Render()
{
	// 陣列中的目前位置
	int tempPos = 0;

	uint8_t** matrix = lightMap->GetMatrix();

	for (int i = 0; i < width; i++) {

		// 判斷白建和黑建，來設定鍵長
		bool whiteKey = isWhiteKey(startPitch + i);

		memcpy(
			&lightArray.channel[0].leds[tempPos],
			whiteKey ? &matrix[i][0] : &matrix[i][height - blackKeyHeight],
			whiteKey ? height : blackKeyHeight);
		
		tempPos += whiteKey ? height : blackKeyHeight;
	}

	return 0;
}

int WS2812v10Renderer::SendToDriver()
{
	ws2811_return_t ret;
	if ((ret = ws2811_render(&lightArray)) != WS2811_SUCCESS)
	{
		fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
		// TODO: 噴錯誤
	}

	return 0;
}

bool WS2812v10Renderer::isWhiteKey(int key)
{
	switch (key % 12) {
	case 0:
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
	case 11:
		return true;
		break;
	default:
		return false;
		break;
	}

}
