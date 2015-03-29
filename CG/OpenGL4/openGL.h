#include "main.h"

class OpenGLContext{
	private: 	
		int windowHeight;
		int windowWidth;

	public: 	
		OpenGLContext(void); 
		OpenGLContext(int argc, char* argv[]); 
		~OpenGLContext(void);
		void reshapeWindow(int w, int h);
		void renderScene(void);
		void testOpenGL(void);
		void Initialize(void);
		void InitWindow(void);
	protected:

}
