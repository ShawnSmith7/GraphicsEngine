#include "Layout.h"

Layout::Layout() {}

Layout::Layout(const std::vector<AttributePointer>& layout) :
    layout(layout) {}

void Layout::set(const std::vector<AttributePointer>& layout) {
    this->layout = layout;
}

std::vector<AttributePointer> Layout::get() const {
    return layout;
}

void Layout::apply() const {
    for (AttributePointer attributePointer : layout) {
        VertexArray::enableAttribute(attributePointer.i);
        VertexArray::setAttributePointer(attributePointer.i, 
                                        attributePointer.size, 
                                        attributePointer.type, 
                                        attributePointer.normalized, 
                                        attributePointer.stride, 
                                        attributePointer.offset);
    }
}