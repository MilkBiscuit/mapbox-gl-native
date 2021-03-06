#include <mbgl/style/types.hpp>
#include <mbgl/util/enum.hpp>

namespace mbgl {

using namespace style;

MBGL_DEFINE_ENUM(SourceType, {
    { SourceType::Vector, "vector" },
    { SourceType::Raster, "raster" },
    { SourceType::GeoJSON, "geojson" },
    { SourceType::Video, "video" },
    { SourceType::Annotations, "annotations" },
});

MBGL_DEFINE_ENUM(VisibilityType, {
    { VisibilityType::Visible, "visible" },
    { VisibilityType::None, "none" },
});

MBGL_DEFINE_ENUM(TranslateAnchorType, {
    { TranslateAnchorType::Map, "map" },
    { TranslateAnchorType::Viewport, "viewport" },
});

MBGL_DEFINE_ENUM(RotateAnchorType, {
    { RotateAnchorType::Map, "map" },
    { RotateAnchorType::Viewport, "viewport" },
});

MBGL_DEFINE_ENUM(CirclePitchScaleType, {
    { CirclePitchScaleType::Map, "map" },
    { CirclePitchScaleType::Viewport, "viewport" },
});

MBGL_DEFINE_ENUM(LineCapType, {
    { LineCapType::Round, "round" },
    { LineCapType::Butt, "butt" },
    { LineCapType::Square, "square" },
});

MBGL_DEFINE_ENUM(LineJoinType, {
    { LineJoinType::Miter, "miter" },
    { LineJoinType::Bevel, "bevel" },
    { LineJoinType::Round, "round" },
    { LineJoinType::FakeRound, "fakeround" },
    { LineJoinType::FlipBevel, "flipbevel" },
});

MBGL_DEFINE_ENUM(SymbolPlacementType, {
    { SymbolPlacementType::Point, "point" },
    { SymbolPlacementType::Line, "line" },
});

MBGL_DEFINE_ENUM(TextAnchorType, {
    { TextAnchorType::Center, "center" },
    { TextAnchorType::Left, "left" },
    { TextAnchorType::Right, "right" },
    { TextAnchorType::Top, "top" },
    { TextAnchorType::Bottom, "bottom" },
    { TextAnchorType::TopLeft, "top-left" },
    { TextAnchorType::TopRight, "top-right" },
    { TextAnchorType::BottomLeft, "bottom-left" },
    { TextAnchorType::BottomRight, "bottom-right" }
});

MBGL_DEFINE_ENUM(TextJustifyType, {
    { TextJustifyType::Center, "center" },
    { TextJustifyType::Left, "left" },
    { TextJustifyType::Right, "right" },
});

MBGL_DEFINE_ENUM(TextTransformType, {
    { TextTransformType::None, "none" },
    { TextTransformType::Uppercase, "uppercase" },
    { TextTransformType::Lowercase, "lowercase" },
});

MBGL_DEFINE_ENUM(AlignmentType, {
    { AlignmentType::Map, "map" },
    { AlignmentType::Viewport, "viewport" },
    { AlignmentType::Undefined, "undefined" },
});

MBGL_DEFINE_ENUM(IconTextFitType, {
    { IconTextFitType::None, "none" },
    { IconTextFitType::Both, "both" },
    { IconTextFitType::Width, "width" },
    { IconTextFitType::Height, "height" },
});

} // namespace mbgl
