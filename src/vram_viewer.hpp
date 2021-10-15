#ifndef VRAM_VIEWER_HPP
#define VRAM_VIEWER_HPP

#include <QMainWindow>
#include <QImage>

class GameWindow;
class QGraphicsScene;
class QGraphicsPixmapItem;
class QGraphicsView;
class QCheckBox;

#include "game_instance.hpp"

class VRAMViewer : public QMainWindow {
    Q_OBJECT
    
public:
    VRAMViewer(GameWindow *window);
    ~VRAMViewer() override;

    void refresh_view();

private:
    GameWindow *window;

    QImage gb_tileset_image;
    std::uint32_t gb_tileset_image_data[GameInstance::GB_TILESET_WIDTH * GameInstance::GB_TILESET_HEIGHT] = {};

    QGraphicsScene *gb_tilemap_scene;
    QGraphicsView *gb_tilemap_view;
    QGraphicsPixmapItem *gb_tilemap_pixmap;
    QImage gb_tilemap_image;
    std::uint32_t gb_tilemap_image_data[GameInstance::GB_TILEMAP_WIDTH * GameInstance::GB_TILEMAP_HEIGHT] = {};
    QCheckBox *gb_tilemap_show_viewport_box;

    void redraw_tilemap() noexcept;

};

#endif
