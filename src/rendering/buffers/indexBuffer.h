#pragma once

class IndexBuffer
{
public:
	IndexBuffer(unsigned int* data, unsigned int count);

	inline unsigned int getCount() const { return count; }
	inline unsigned int getId() const { return id; }

	void bind();
	void unbind();

	~IndexBuffer();
private:
	unsigned int id;
	unsigned int count;

	unsigned int* data;
};