#pragma once

#include "Model.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include <memory>
#include <unordered_map>

namespace  DedOs {
	struct TransformComponent {
		glm::vec3 translation{ };
		glm::vec3 scale{ 1.f,1.f,1.f };
		glm::vec3 rotation;

		glm::mat4 mat4();
		glm::mat3 normalMatrix();
	};
	class GameObject
	{
	public:
		using id_t = unsigned int;
		using Map = std::unordered_map<id_t, GameObject>;

		static GameObject createGameObject() {
			static id_t currentId = 0;
			return GameObject{ currentId++ };
		};

		GameObject(const GameObject&) = delete;
		void operator=(const GameObject&) = delete;
		GameObject(GameObject&&) = default;
		GameObject& operator=(GameObject&&) = default;

		std::shared_ptr<Model> model{};
		glm::vec3 color{};
		TransformComponent transform{};

		id_t getId() { return id; }

	private:
		GameObject(id_t objId) :id{ objId } {};

		id_t id;
	};

}
