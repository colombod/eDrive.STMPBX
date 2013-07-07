#include "eDrive.h"
#include "OscMessage.h"


namespace mUBreeze{
	namespace eDrive{

		// default constructor
		Engine::Engine(){
            m_channelCount = 0;
            ResetBuffers();
		}

		// the destructor is resposible to lcean up
		Engine::~Engine(){
			m_channelCount = 0;
			ResetBuffers();
            FlushInbox();
            FlushOutbox();
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
        
        void Engine::FlushInbox(){
            std::queue<OscMessage*> empty;
            std::swap(m_inbox, empty);
        }
        
        void Engine::FlushOutbox(){
            std::queue<OscMessage*> empty;
            std::swap(m_outbox, empty);
        }
        
        float* const Engine::GetIncomingSampleBuffer(){
            return m_ptrIncomingSamples;
        }
        const float* const Engine::GetOutgoingSampleBuffer(){
            return m_ptrOututgoingSamples;
        }
        
		void Engine::ResetBuffers(){
            if(m_ptrIncomingSamples)
            {
                delete (m_ptrIncomingSamples);
            }
            
            if(m_ptrOututgoingSamples)
            {
                delete(m_ptrOututgoingSamples);
            }
			
			if(m_channelCount > 0)
			{
                m_ptrIncomingSamples = new float[m_channelCount];
                m_ptrOututgoingSamples = new float[m_channelCount];
			}
		}
	}
}
