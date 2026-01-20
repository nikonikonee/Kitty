#include "RR_Unity.h"

namespace SDK::RR::Unity {
	Structs::Unity::Vector3 Transform::get_position() { return Pointers::Unity::Transform.get_position[this].Invoke().Unbox(); }
	Structs::Unity::Vector3 Transform::get_forward() { return Pointers::Unity::Transform.get_forward[this].Invoke().Unbox(); }

	void Transform::set_position(Structs::Unity::Vector3 value) {
		void* args[1] = { &value };
		Pointers::Unity::Transform.set_position[this].Invoke(args);
	}

	void Transform::set_localPosition(Structs::Unity::Vector3 value) {
		void* args[1] = { &value };
		Pointers::Unity::Transform.set_localPosition[this].Invoke(args);
	}

	void Transform::set_parent(Transform* value) {
		void* args[1] = { value };
		Pointers::Unity::Transform.set_parent[this].Invoke(args);
	}

	Transform* Transform::GetChild(int index) {
		void* args[1] = { &index };
		return (Transform*)Pointers::Unity::Transform.GetChild[this].Invoke(args).Get();
	}

	int Transform::GetChildCount() { return Pointers::Unity::Transform.GetChildCount[this].Invoke().Unbox(); }
}

namespace SDK::RR::Unity {
	Transform* GameObject::get_transform() { return (Transform*)Pointers::Unity::GameObject.get_transform[this].Invoke().Get(); }

	GameObject* GameObject::ctor(const char* name) {
		auto newGameObject = Pointers::Unity::GameObject.klass.New();
		if (newGameObject) {
			auto nameString = IL2CPP::Utils::il2cpp_string_new(name);
			void* args[1] = { nameString };

			Pointers::Unity::GameObject.ctor[newGameObject].Invoke(args);
			return (GameObject*)newGameObject;
		}
	}
}

namespace SDK::RR::Unity {
	void SphereCollider::set_raidus(float value) {
		void* args[1] = { &value };
		Pointers::Unity::SphereCollider.set_radius[this].Invoke(args);
	}
}

namespace SDK::RR::Unity {
	Shader* Shader::Find(const char* name) {
		auto stringName = IL2CPP::Utils::il2cpp_string_new(name);
		void* args[1] = { stringName };
		return (Shader*)Pointers::Unity::Shader.Find.Invoke(args).Get();
	}

	Structs::Mono::String* Shader::GetPropertyName(Shader* shader, int propertyIndex) {
		void* args[2] = { shader, &propertyIndex };
		return Pointers::Unity::Shader.GetPropertyName.Invoke(args).Get();
	}

	int Shader::GetPropertyCount() { return Pointers::Unity::Shader.GetPropertyCount[this].Invoke().Unbox(); }
}

namespace SDK::RR::Unity {
	Material* Material::ctor(Shader* shader) {
		auto materialObject = IL2CPP::Utils::il2cpp_object_new(Globals::Vars::Runtime::Native::Material);
		void* args[1] = { shader };
		Pointers::Unity::Material.ctor[materialObject].Invoke(args);
		return (Material*)materialObject;
	}

	void Material::SetInt(const char* name, int value) {
		auto stringName = IL2CPP::Utils::il2cpp_string_new(name);
		void* args[2] = { stringName, &value };
		Pointers::Unity::Material.SetInt[this].Invoke(args);
	}

	void Material::SetColor(const char* name, Structs::Unity::Vector4 value) {
		auto stringName = IL2CPP::Utils::il2cpp_string_new(name);
		void* args[2] = { stringName, &value };
		Pointers::Unity::Material.SetColor[this].Invoke(args);
	}
}

namespace SDK::RR::Unity {
	Material* Renderer::get_material() { return (Material*)Pointers::Unity::Renderer.get_material[this].Invoke().Get(); }

	void Renderer::set_material(Material* value) {
		void* args[1] = { value };
		Pointers::Unity::Renderer.set_material[this].Invoke(args);
	}
}

namespace SDK::RR::Unity {
	void LineRenderer::set_startWidth(float value) {
		void* args[1] = { &value };
		Pointers::Unity::LineRenderer.set_startWidth[this].Invoke(args);
	}

	void LineRenderer::set_endWidth(float value) {
		void* args[1] = { &value };
		Pointers::Unity::LineRenderer.set_endWidth[this].Invoke(args);
	}

	void LineRenderer::set_useWorldSpace(bool value) {
		void* args[1] = { &value };
		Pointers::Unity::LineRenderer.set_useWorldSpace[this].Invoke(args);
	}

	void LineRenderer::set_startColor(Structs::Unity::Vector4 value) {
		void* args[1] = { &value };
		Pointers::Unity::LineRenderer.set_startColor[this].Invoke(args);
	}

	void LineRenderer::set_endColor(Structs::Unity::Vector4 value) {
		void* args[1] = { &value };
		Pointers::Unity::LineRenderer.set_endColor[this].Invoke(args);
	}

	void LineRenderer::set_positionCount(int value) {
		void* args[1] = { &value };
		Pointers::Unity::LineRenderer.set_positionCount[this].Invoke(args);
	}

	void LineRenderer::SetPosition(int index, Structs::Unity::Vector3 position) {
		void* args[2] = { &index, &position };
		Pointers::Unity::LineRenderer.SetPosition[this].Invoke(args);
	}
}

namespace SDK::RR::Unity {
	AssetBundle* AssetBundle::LoadFromFile(const char* path) {
		auto pathString = IL2CPP::Utils::il2cpp_string_new(path);
		void* args[1] = { pathString };
		return (AssetBundle*)Pointers::Unity::AssetBundle.LoadFromFile.Invoke(args).Get();
	}
}

namespace SDK::RR::Unity {
	Camera* Camera::getCamera(int index) { return (Camera*)Pointers::Utils::getCamera(index); }
	Structs::Unity::Vector3 Camera::WorldToScreenPoint(Structs::Unity::Vector3 position) { return Pointers::Utils::WorldToScreenPoint(this, position); }
}

namespace SDK::RR::Unity {
	float Time::get_time() { return Pointers::Unity::Time.get_time(); }

	void Time::set_timeScale(float value) {
		void* args[1] = { &value };
		Pointers::Unity::Time.set_timeScale.Invoke(args);
	}
}

namespace SDK::RR::Unity {
	Texture2D* Texture2D::ctor(int width, int height) {
		auto textureObject = Pointers::Unity::Texture2D.klass.New();

		void* args[2] = { &width, &height };

		Pointers::Unity::Texture2D.ctor[textureObject].Invoke(args);

		return (Texture2D*)textureObject;
	}
}

namespace SDK::RR::Unity {
	bool ImageConversion::LoadImageTex(Texture2D* tex, Structs::Mono::Array<uint8_t**>* data) {
		void* args[2] = { tex, data };
		
		return Pointers::Unity::ImageConversion.LoadImageTex.Invoke(args).Unbox();
	}
}