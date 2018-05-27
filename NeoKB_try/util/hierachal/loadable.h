#ifndef LOADABLE_H
#define LOADABLE_H

#include "Cachable.h"
#include "../MtoType.h"
#include<vector>
#include<string>

using namespace std;
using namespace Util;

/*
 * pointer of every variable
 * https://stackoverflow.com/questions/19710601/any-type-of-pointer-can-point-to-anything
 *
 * ���UprivateLoad����k
 * �bconstructor�̭���@��registerPrivateLoader("���O�W��", privateLoad);
 */



/*
 * when child class call parent class's protected function to access private variable, it only
 * access his own private variable, but not access child class's private variable
 *
 * c++ can't automatically register private function. so we do it manually by put 
 * "registerPrivateLoader()" into every constructor of child classes. So that
 * we could find a vector of loaders of each class inherited from Loadable
 * and then call them
 *
 */

namespace Util {
namespace Hierachal{


	class Loadable: public Cachable {

		/// <summary>
		/// for register_load() to ergister every loaders into this vector
		/// </summary>
		vector<MTO_FUNC_POINTER> loaders;

		/// <summary>
		/// �u���i��load���a��
		/// </summary>
		int load();

	public:

		Loadable();

		/// <summary>
		/// call every parent class's private load() function
		/// 1. take out all loaders and all parameters
		/// 2. call every loaders with those parameter
		/// �o�Ӧ���public�����رM�ΡA�q�`�@���C�����u���@�ӡA�|��parent�]���n�[�J�����
		/// </summary>
		int Async();

		LoadState GetLoadState();

		/// <summary>
		/// override HasParent���禡�A�b�̭��[�Whandler
		/// </summary>
		int SetParent(HasParent* p);

	protected:

		/// <summary>
		/// register loader, must do in every loadable derived class 
		/// </summary>
		/// <param name="l">private loader</param>
		int registerLoad(int(*l)());

		/// <summary>
		/// ��Ҧ���load��������@��
		/// �o�Ӧ���childaddable�Ϊ�
		/// </summary>
		int Load();

	private:

		class LoadStateHandler;
		class NoParentHandler;
		class NotLoadedHandler;
		class LoadingHandler;
		class ReadyHandler;

		LoadStateHandler* loadStateHandler;
		NoParentHandler noParentHandler;
		NotLoadedHandler notLoadedHandler;
		LoadingHandler loadingHandler;
		ReadyHandler readyHandler;


		class LoadStateHandler {
		public:
			virtual LoadState GetLoadState() = 0;
			virtual int HandleLoad() = 0;
			virtual int Async() = 0;
			virtual int SetParent(HasParent* p) = 0;
		protected:
			Loadable& loadable;
			LoadStateHandler(Loadable& l);
		};

		class NoParentHandler : public LoadStateHandler {
		public:
			NoParentHandler(Loadable& l);
			LoadState GetLoadState();
			int HandleLoad();
			int Async();
			int SetParent(HasParent* p);
		};

		class NotLoadedHandler : public LoadStateHandler {
		public:
			NotLoadedHandler(Loadable& l);
			LoadState GetLoadState();
			int HandleLoad();
			int Async();
			int SetParent(HasParent* p);
		};

		class LoadingHandler : public LoadStateHandler {
		public:
			LoadingHandler(Loadable& l);
			LoadState GetLoadState();
			int HandleLoad();
			int Async();
			int SetParent(HasParent* p);
		};

		class ReadyHandler : public LoadStateHandler {
		public:
			ReadyHandler(Loadable& l);
			LoadState GetLoadState();
			int HandleLoad();
			int Async();
			int SetParent(HasParent* p);
		};

	};


	/// <summary>
	/// Possible states of a <see cref="Drawable"/> within the loading pipeline.
	/// </summary>
	enum LoadState {
		/// <summary>
		/// Not loaded, and no load has been initiated yet.
		/// </summary>
		LoadStateNoParent,
		/// <summary>
		/// Not loaded, and no load has been initiated yet.
		/// </summary>
		LoadStateNotLoaded,
		/// <summary>
		/// Currently loading (possibly and usually on a background
		/// thread via <see cref="Drawable.LoadAsync(Game, Drawable, Action)"/>).
		/// </summary>
		LoadStateLoading,
		/// <summary>
		/// Loading is complete, but has not yet been finalized on the update thread
		/// (<see cref="Drawable.LoadComplete"/> has not been called yet, which
		/// always runs on the update thread and requires <see cref="Drawable.IsAlive"/>).
		/// </summary>
		LoadStateReady
		/// <summary>
		/// Loading is fully completed and the Drawable is now part of the scene graph.
		/// </summary>
		// LoadStateLoaded
	};



}}




#endif