#pragma once
#include <Magnum/GL/Framebuffer.h>
#include <Magnum/GL/Renderbuffer.h>
#include <Magnum/Magnum.h>
#include "esp/gfx/MeshVisualizerDrawable.h"

class ObjectPickingHelper {
 public:
  /**
   * @brief Constructor
   * @param viewportSize the size of the viewport in w x h format
   */
  ObjectPickingHelper(Magnum::Vector2i viewportSize);
  ~ObjectPickingHelper(){};

  /**
   * @brief  Recreate object ID reading renderbuffers that depend on viewport
   * size
   * @param viewportSize the size of the viewport in w x h format
   */
  ObjectPickingHelper& recreateFramebuffer(Magnum::Vector2i viewportSize);

  /**
   *@brief Prepare to draw: it will bind the framebuffer, map color attachement,
   *clear depth, background color
   */
  ObjectPickingHelper& prepareToDraw();
  /**
   * @brief set viewport for framebuffer, which must be called in viewportEvent
   */
  ObjectPickingHelper& setViewport(Magnum::Vector2i viewportSize);
  /**
   * @brief get the object id, aka, the drawable id defined in Drawable class
   * @param eventPosition, mouse event position
   * @param windowSize, the size of the GUI window
   */
  unsigned int getObjectId(Magnum::Vector2i mouseEventPosition,
                           Magnum::Vector2i windowSize);

 protected:
  int64_t selectedDrawableId_ = -1;

  // framebuffer for drawable selection
  Magnum::GL::Framebuffer selectionFramebuffer_{Magnum::NoCreate};
  Magnum::GL::Renderbuffer selectionDepth_;
  Magnum::GL::Renderbuffer selectionDrawableId_;

  esp::gfx::MeshVisualizerDrawable* meshVisualizerDrawable{};
  ObjectPickingHelper& mapForDraw();
};