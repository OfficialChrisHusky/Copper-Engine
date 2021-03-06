//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "Copper/Core/Core.h"

namespace Copper {

	class Texture {

	public:
		static Shared<Texture> Create(const char* path);
		virtual ~Texture() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

	};

}