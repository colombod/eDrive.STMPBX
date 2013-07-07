//
//  eDrive.h
//  eDrive.CompileTest
//
//  Created by Diego Colombo on 07/07/2013.
//
//

//
//  OscMessage.h
//  eDrive.CompileTest
//
//  Created by Diego Colombo on 07/07/2013.
//
//

#ifndef eDrive_h
#define eDrive_h
#include <queue>

namespace  mUBreeze{  
	namespace  eDrive{
        class OscMessage;
		class  Engine{  
			
		private:
			int m_channelCount;
			int m_samplingRate;
			float* m_ptrIncomingSamples;
			float* m_ptrOututgoingSamples;
			
            std::queue<OscMessage*> m_inbox;
            std::queue<OscMessage*> m_outbox;
			void ResetBuffers();
        protected:
            /*
			 Override for sutom initialisation step
             */
			virtual  void  OnInitialising();
            /*
             Flushes and clears all inbox messages
             */
            void FlushInbox();
            
            /*
             Flushes and clears all outbox messages
             */
            void FlushOutbox();

		public:
			Engine();  
			virtual  ~Engine();  
			/*
			 Performs  a  step  
			 */  
			void  DoStep();  
						
			/*
			 Call this at the very beginning
			 */
			
			void  Initialise(int  samplingRate, int channelCount);  
				
			
            int GetBufferSize() { return m_channelCount;}
            
            float* const GetIncomingSampleBuffer();
            
            const float* const GetOutgoingSampleBuffer();
		};
	}
	
}
#endif