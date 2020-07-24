#pragma once
#include <vector>

class VertexBuffer
{
public:
	VertexBuffer(float* data, unsigned int count, std::vector<int> layout);

	inline std::vector<int> getLayout() const { return layout; }
	inline unsigned int getId() const { return id; }

	inline std::vector<int> setLayout(std::vector<int> layout) { this->layout = layout; }

	void bind();
	void unbind();

	~VertexBuffer();
private:
	unsigned int id;
	float* data;
	unsigned int count;

	std::vector<int> layout;
};