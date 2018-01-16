/********************************************************************
filename:   WXParticleElement.h

purpose:    a particle system effect element.
*********************************************************************/

#ifndef __PARTICLEELEMENT_H__
#define __PARTICLEELEMENT_H__

// fairy header
#include "WXEffectElement.h"
#include "Core/WXPrerequisites.h"

// ogre header
namespace Ogre	{
	class ParticleSystem;
}

namespace WX	{

	class ParticleElement : public EffectElement
	{
	public:

		// ��������
		class CmdParticleSystem : public Ogre::ParamCommand
        {
        public:
            String doGet(const void* target) const;
            void doSet(void* target, const String& val);
#if OGRE_STRING_INTERFACE_COPY
            virtual void doCopy(void* target, const void* source);
#endif 
        };       

		/////////////////////////////////////////////////////////////
		ParticleElement(const String &type, System *system);
		~ParticleElement();
		
		virtual bool createRenderInstance(void);
		virtual void destroyRenderInstance(void);
		virtual void updateRenderInstance( Real time, TransformInfo &info );

		virtual void destroyMe(void);

		void setParticleSystemName(const String &name);

		const String &getParticleSystemName(void) const	{	return mParticleSystemName;	}

		Ogre::ParticleSystem * getParticleSystem(void)	
		{
			return mParticleSystem;
		}

		void setParticleSystem(Ogre::ParticleSystem *system)
		{
			assert (system);
			mParticleSystem = system;
		}

		String mParticleSystemName;

		virtual void sleep(void);
		
		virtual void active(void);

		virtual bool existVisualElements(void);

		virtual void shutdown(void);

        virtual void setColour( const Ogre::ColourValue& colour );

        /// ����visible flag
        virtual void setVisibleFlag(uint32 flags);

        /// ������Ч����ʾ������
        virtual void setVisible(bool visible);

	protected:

		bool _createParticleSystem(void);
		void _destroyParticleSystem(void);

        /// ����colour affector�е���ɫ
        void _setAffectorColour(void);

	protected:

		Ogre::ParticleSystem *mParticleSystem;

		bool mIsEmitterEnabled;

        /// ��������ϵͳ��ԭ������ɫ����������ɫӰ�����е�ԭ��ɫ��Ҳ����������ϵͳ����ɫ
        typedef std::map<String, Ogre::ColourValue> ColourMap;
        ColourMap mColourMap;

        /// ��Ҫ��update��ʱ�������ɫ
        bool mNeedUpdateColour;
        /// ��ǰ���õ���ɫ
        Ogre::ColourValue mCurrentColour;

		////////////////////////////////////////////////////////////////
		static CmdParticleSystem msParticleSystemCmd;
	};
}

#endif