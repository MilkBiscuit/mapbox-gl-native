#include <mbgl/annotation/line_annotation_impl.hpp>
#include <mbgl/annotation/annotation_manager.hpp>
#include <mbgl/style/style.hpp>
#include <mbgl/style/layers/line_layer.hpp>

namespace mbgl {

using namespace style;

LineAnnotationImpl::LineAnnotationImpl(AnnotationID id_, LineAnnotation annotation_, uint8_t maxZoom_)
    : ShapeAnnotationImpl(id_, maxZoom_),
      annotation({ ShapeAnnotationGeometry::visit(annotation_.geometry, CloseShapeAnnotation{}), annotation_.opacity, annotation_.width, annotation_.color }) {
}

void LineAnnotationImpl::updateStyle(Style& style) const {
    Layer* layer = style.getLayer(layerID);
    LineLayer* lineLayer = layer ? layer->as<LineLayer>() : nullptr;

    if (!lineLayer) {
        lineLayer = style.addLayer(
            std::make_unique<LineLayer>(layerID, AnnotationManager::SourceID),
            AnnotationManager::PointLayerID)->as<LineLayer>();
        lineLayer->setSourceLayer(layerID);
    }

    lineLayer->setLineJoin(LineJoinType::Round);
    lineLayer->setLineOpacity(annotation.opacity);
    lineLayer->setLineWidth(annotation.width);
    lineLayer->setLineColor(annotation.color);
}

const ShapeAnnotationGeometry& LineAnnotationImpl::geometry() const {
    return annotation.geometry;
}

} // namespace mbgl
