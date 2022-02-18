#pragma once


namespace Engine
{
	/*
		to increase overall performance, resources should be organized in a pool to reduce load/unload
	*/
	class Resource
	{
	public:
		Resource() = default;
		virtual ~Resource() = default;

	public:
		virtual void apply() {};

	protected:
		bool m_isLoaded = false;
	};


	//class ResourcePool
	//{
	//public:
	//	static ResourcePool* getInstance();

	//private:
	//	std::vector<Resource*> m_resources;

	//private:
	//	ResourcePool();
	//	~ResourcePool();
	//};
}