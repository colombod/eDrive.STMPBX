#pragma once 
#include <vector>

namespace  mUBreeze{  
	namespace  eDrive{  
		class  Engine{  
			
		private:
			int m_channelCount;
			int m_samplingRate;
			std::vector<float> m_incomingSamples;
			std::vector<float> m_oututgoingSamples;
			
			void ResetBuffers();

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
				
			/*
			 Override for sutom initialisation step
			*/
			virtual  void  OnInitialising();  
		};
	}
	
}
