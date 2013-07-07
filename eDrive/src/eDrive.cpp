#include "eDrive.hpp"

namespace mUBreeze{
	namespace eDrive{

		// default constructor
		Engine::Engine(){
		}

		// the destructor is resposible to lcean up
		Engine::~Engine(){
			m_channelCount = 0;
			ResetBuffers();
		}

		void Engine::Initialise(int samplingRate, int channelCount){
			m_samplingRate = samplingRate;
			m_channelCount = channelCount;
			OnInitialising();
		}

		void Engine::OnInitialising(){
	
		}

		void Engine::DoStep(){
			if(m_channelCount > 0)
			{
			}
	
		}
		
		void Engine::ResetBuffers(){
			m_incomingSamples.clear();
			m_oututgoingSamples.clear();
			
			if(m_channelCount > 0)
			{
				m_incomingSamples.resize(m_channelCount, 0.0f);
				m_oututgoingSamples.resize(m_channelCount, 0.0f);
			}
		}
	}
}
