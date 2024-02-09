//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_property.h"
#include "modules/svg/include/SkSVGTypes.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_diffuse_lighting.h"
/*
//
// SkSVGProperty
//
// T * operator-> ()
// const T * operator-> ()
// T & operator* ()
// const T & operator* ()
void SkSVGProperty_delete(SkSVGProperty *svgProperty) {
    delete svg;
}

SkSVGProperty_new()
SkSVGProperty_new(SkSVGPropertyState state)
SkSVGProperty_new(const T &value)
SkSVGProperty_new(T &&value)
void SkSVGProperty_init (SkSVGProperty *svgProperty, Args &&... args)
constexpr bool SkSVGProperty_isInheritable (SkSVGProperty *svgProperty)
bool SkSVGProperty_isValue (SkSVGProperty *svgProperty)
T * SkSVGProperty_getMaybeNull (SkSVGProperty *svgProperty)
void SkSVGProperty_set (SkSVGProperty *svgProperty, SkSVGPropertyState state)
void SkSVGProperty_set (SkSVGProperty *svgProperty, const T &value)
void SkSVGProperty_set (SkSVGProperty *svgProperty, T &&value)
 */