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
		/// key:�w�骩�� value:renderer�W��
		///	</summary>
		static map<string, string> renderers;

		/// <summary>
		/// �bload���ɭԡA�ھ�config�A��MapAlgo�\�i�h
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