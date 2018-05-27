#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <string>
#include "../Map/Map.h"



using namespace std;
using namespace Base::Graphic::Map;


namespace Base {
namespace Graphic {
namespace Renderer {

	class Renderer {

		int load();

		/// <summary>
		/// key:硬體版本 value:renderer名稱
		///	</summary>
		static map<string, string> renderers;

		/// <summary>
		/// 在load的時候，根據config，把MapAlgo擺進去
		///	</summary>
		int RegisterHWMapAlgo(HardwareMapAlgo* hwma);

	public:

		int RegisterMap(Map* m);

		static int RegisterRenderer(string hwVersion, string rendererName);

		static Renderer* GetRenderer(string hwVersion);

		virtual int Render();

		virtual int SendToDriver();

	protected:

		Map* map;

		HardwareMapAlgo* hwMapAlgo;
		
	};




}}}


#endif