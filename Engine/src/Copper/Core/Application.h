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

#include "Copper/Core/Core.h"
#include "Copper/Core/Window.h"
#include "Copper/Core/Layer.h"
#include "Copper/Core/LayerStack.h"

#include "Copper/Debug/Log.h"

#include "Copper/Events/Event.h"
#include "Copper/Events/ApplicationEvent.h"
#include "Copper/Events/KeyEvent.h"
#include "Copper/Events/MouseEvent.h"

#include "Copper/Renderer/Renderer.h"
#include "Copper/Renderer/Buffer.h"
#include "Copper/Renderer/VertexArray.h"
#include "Copper/Renderer/Shader.h"
#include "Copper/Renderer/Texture.h"

#include "Copper/ImGui/ImGuiLayer.h"

#include "Copper/Scene/Transform.h"
#include "Copper/Scene/Mesh.h"
#include "Copper/Scene/Camera.h"

#include "Editor/Core/Editor.h"

namespace Copper {

	class Application {

	public:
		//The Initialization Functions
		void Initialize();

		//The Runtime Functions
		void OnEvent(Event& e);
		void Run();

		void PushLayer(Layer* layer) { layerStack.PushLayer(layer); }
		void PushOverlay(Layer* overlay) { layerStack.PushOverlay(overlay); }

		//The Shutdown Functions
		void Shutdown();

		//Functions to Get Application Variables
		inline static Application& Get() { return *instance; }
		inline Window& GetWindow() { return *window; }
		inline void* GetGLFWWindow() { return window->GetWindowPointer(); }

	private:
		static Application* instance;

		//Running bool and Window Pointer
		bool running = true;
		std::unique_ptr<Window> window;

		//Our Event Dispatcher
		EventDispatcher dispatcher;

		//Layers
		LayerStack layerStack;
		ImGuiLayer* imGuiLayer;

		//Rendering Variables
		Unique<Renderer> renderer;

		Shared<VertexArray> vao;
		Shared<VertexBuffer> vbo;
		Shared<IndexBuffer> ibo;

		Shared<Shader> shader;

		Shared<Texture> texture;

		//Model and Camera
		Shared<Mesh> mesh;
		Shared<Camera> cam;

		//Editor
#ifdef CU_EDITOR

		Unique<Editor::Editor> editor;

#endif

		//Event Functions
		bool OnWindowClose(Event& e);
		bool OnWindowResize(Event& e);

	};

	Application* CreateApplication();

}