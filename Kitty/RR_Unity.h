#pragma once
#include "RR_Includes.h"
#include "RR_Base.h"
#include "RR_System.h"

namespace SDK::RR::Unity {
	struct Transform : Base::Component {
		Structs::Unity::Vector3 get_position();

		Structs::Unity::Vector3 get_forward();

		void set_position(Structs::Unity::Vector3 value);
		void set_localPosition(Structs::Unity::Vector3 value);

		void set_parent(Transform* value);

		Transform* GetChild(int index);
		int GetChildCount();
	};

	struct GameObject : Base::Object {
		template <typename T>
		T GetComponent(System::Type* type) {
			void* args[1] = { type };
			return (T)Pointers::Unity::GameObject.GetComponent[this].Invoke(args).Get();
		}

		template <typename T>
		T GetComponentInChildren(System::Type* type) {
			void* args[1] = { type };
			return (T)Pointers::Unity::GameObject.GetComponentInChildren[this].Invoke(args).Get();
		}

		template <typename T>
		Structs::Mono::Array<T*>* GetComponentsInChildren(System::Type* type) {
			void* args[1] = { type };
			return (Structs::Mono::Array<T*>*)Pointers::Unity::GameObject.GetComponentsInChildren[this].Invoke(args).Get();
		}

		template <typename T>
		Structs::Mono::Array<T*>* GetComponents(System::Type* type) {
			void* args[1] = { type };
			return (Structs::Mono::Array<T*>*)Pointers::Unity::GameObject.GetComponents[this].Invoke(args).Get();
		}

		template <typename T>
		T AddComponent(System::Type* componentType) {
			void* args[1] = { componentType };
			return (T)Pointers::Unity::GameObject.AddComponent[this].Invoke(args).Get();
		}

		Transform* get_transform();

		static GameObject* ctor(const char* name);
	};

	struct SphereCollider {
		void set_raidus(float value);
	};

	struct Shader : Base::Object {
		static Shader* Find(const char* name);
		static Structs::Mono::String* GetPropertyName(Shader* shader, int propertyIndex);
		int GetPropertyCount();
	};

	struct Material : Base::Object {
		static Material* ctor(Shader* shader);
		void SetInt(const char* name, int value);
		void SetColor(const char* name, Structs::Unity::Vector4 value);
	};

	struct Renderer : Base::Component {
		Material* get_material();
		void set_material(Material* value);
	};

	struct SkinnedMeshRenderer : Renderer {};

	struct LineRenderer : Renderer {
		void set_startWidth(float value);
		void set_endWidth(float value);

		void set_useWorldSpace(bool value);

		void set_startColor(Structs::Unity::Vector4 value);
		void set_endColor(Structs::Unity::Vector4 value);
	
		void set_positionCount(int value);

		void SetPosition(int index, Structs::Unity::Vector3 position);
	};

	struct AssetBundle : Base::Object {
		static AssetBundle* LoadFromFile(const char* path);

		template <typename T>
		T LoadAsset(const char* name) {
			auto nameString = IL2CPP::Utils::il2cpp_string_new(name);
			void* args[1] = { nameString };
			return (T)Pointers::Unity::AssetBundle.LoadAsset[this].Invoke(args).Get();
		}

		template <typename T>
		Structs::Mono::Array<T*>* LoadAllAssets(System::Type* type) {
			void* args[1] = { type };
			return (Structs::Mono::Array<T*>*)Pointers::Unity::AssetBundle.LoadAllAssets[this].Invoke(args).Get();
		}
	};

	struct Camera : Base::Behaviour {
		static Camera* getCamera(int index);

		Structs::Unity::Vector3 WorldToScreenPoint(Structs::Unity::Vector3 position);
	};

	struct Time {
		static float get_time();
		static void set_timeScale(float value);
	};

	struct Texture2D {
		static Texture2D* ctor(int width, int height);
	};

	struct ImageConversion {
		static bool LoadImageTex(Texture2D* tex, Structs::Mono::Array<uint8_t**>* data);
	};
}