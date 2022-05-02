//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Application header. The Application is a class in the Engine Core, any Application
//made with the Copper Engine needs to have a class that derives from this class.
//The Application is going to have functions that Initialize the Application itself, Run the Game Loop
//and shutdown the Application when needed

#pragma once

namespace Copper {

	class Application {

	public:
		void Initialize();
		void Start();
		void Shutdown();

	private:
		//

	};

}