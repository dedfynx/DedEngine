#pragma once

#include "Window.hpp"
#include "Device.hpp"
#include "Renderer.hpp"
#include "RenderSystem.hpp"
#include "GameObject.hpp"
#include "Descriptor.hpp"

//std
#include <memory>
#include <vector>

namespace DedOs {
	class App {
	public : 
		App();
		~App();

		App(const App&) = delete;
		App& operator=(const App&) = delete;

		void run();

		static constexpr int WIDTH = 800, HEIGHT = 600;
		std::string wName = "App";
	private:


		void loadGameObjects();
		
		Window hWin{WIDTH, HEIGHT,wName };
		Device hDevice{hWin};
		Renderer hRenderer{ hWin,hDevice };

		//order matters here
		std::unique_ptr<DescriptorPool> globalPool{};
		GameObject::Map gameObjects;
	};
}