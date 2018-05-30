#ifndef MAP_ALGORITHM_H
#define MAP_ALGORITHM_H

#include"../../../../Graphic/Map/Map.h"

using namespace Base::Graphic::Maps;


namespace Base {
namespace Schedulers {
namespace Events {
namespace Effects {
namespace Algorithms{
	
	template<typename T>
	class MapAlgorithm
	{

	public:

		/// <summary>
		/// construct an immediate effect
		///	</summary>
		MapAlgorithm(int w, int h);

		~MapAlgorithm();

		int RegisterGenerator(GenerateAlgorithm* g);

		int RegisterShifter(ShiftAlgorithm* s);


		/// <summary>
		/// ��evnet�����A�ন�ϮסA�M�Ჾ��L����m�W
		///	</summary>
		virtual int Draw(Map* m, EventProcessor<Event>* e);

	protected:

		Matrix2D<int>* mat;

		/// <summary>
		/// to transform the effect to the map with every parameter relevant.
		/// </summary>
		GenerateAlgorithm* genAlgo;

		/// <summary>
		/// ��ͦn��effect����L���\����m�W
		/// </summary>
		ShiftAlgorithm* shiftAlgo;

	};



	

}}}}}








#endif