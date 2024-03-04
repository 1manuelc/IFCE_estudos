import pygame
import sys
import math

pygame.init()

min_circles = 3
max_circles = 200

radius = 580
num_triangles = 3
show_internal_borders = False

white = (255, 255, 255)
black = (0, 0, 0)

screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
width, height = screen.get_size()
center = (width // 2, height // 2)

pygame.display.set_caption("Círculo Interativo por Shared Vertex")

font = pygame.font.Font(None, 72)
label_font = pygame.font.Font(None, 48)

def draw_circle(num_segments):
    vertices = []
    for i in range(num_segments):
        angle = 2 * math.pi * i / num_segments
        x = int(center[0] + radius * math.cos(angle))
        y = int(center[1] + radius * math.sin(angle))
        vertices.append((x, y))
        
    pygame.draw.polygon(screen, white, vertices, 1)

    if show_internal_borders:
        for i in range(num_segments):
            angle1 = 2 * math.pi * i / num_segments
            angle2 = 2 * math.pi * (i + 1) / num_segments
            x1 = int(center[0] + radius * math.cos(angle1))
            y1 = int(center[1] + radius * math.sin(angle1))
            x2 = int(center[0] + radius * math.cos(angle2))
            y2 = int(center[1] + radius * math.sin(angle2))
            pygame.draw.polygon(screen, white, [center, (x1, y1), (x2, y2)], 1)

def main():
    global num_triangles, show_internal_borders
    slider_rect = pygame.Rect(width / 2.8, height - 100, 400, 10)
    slider_value = num_triangles
    checkbox_rect = pygame.Rect(width / 1.55, height - 120, 50, 50)
    clock = pygame.time.Clock()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    sys.exit()
                elif event.key == pygame.K_LEFT:
                    num_triangles = max(min_circles, num_triangles - 1)
                elif event.key == pygame.K_RIGHT:
                    num_triangles = min(max_circles, num_triangles + 1)
                elif event.key == pygame.K_UP:
                    num_triangles = min(max_circles, num_triangles + 5)
                elif event.key == pygame.K_DOWN:
                  num_triangles = min(max_circles, num_triangles - 5)
                elif event.key == pygame.K_SPACE:
                  if show_internal_borders: show_internal_borders = False
                  else: show_internal_borders = True
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1 and checkbox_rect.collidepoint(event.pos):
                    show_internal_borders = not show_internal_borders

        mouse_x, mouse_y = pygame.mouse.get_pos()

        if slider_rect.collidepoint(mouse_x, mouse_y):
            if pygame.mouse.get_pressed()[0]:
                slider_value = int((mouse_x - slider_rect.left) / slider_rect.width * 100)
                num_triangles = max(min_circles, int(slider_value * 0.01 * max_circles + 2))

        screen.fill(black)

        pygame.draw.rect(screen, white, slider_rect)
        pygame.draw.circle(screen, white, (slider_rect.left + int(slider_rect.width * slider_value / 100), slider_rect.centery), 30)

        pygame.draw.rect(screen, white, checkbox_rect)
        if show_internal_borders:
            pygame.draw.line(screen, black, (checkbox_rect.left + 5, checkbox_rect.centery), (checkbox_rect.right - 5, checkbox_rect.centery), 3)
            pygame.draw.line(screen, black, (checkbox_rect.centerx, checkbox_rect.top + 5), (checkbox_rect.centerx, checkbox_rect.bottom - 5), 3)

        label_triangles = label_font.render("Número de triângulos:", True, white)
        label_triangles_rect = label_triangles.get_rect(topleft=(width / 2.8, height - 160))
        screen.blit(label_triangles, label_triangles_rect)

        label_internal_borders = label_font.render("Mostrar vértices internos:", True, white)
        label_internal_borders_rect = label_internal_borders.get_rect(topleft=(width / 2, height - 114))
        screen.blit(label_internal_borders, label_internal_borders_rect)

        draw_circle(num_triangles)

        text = font.render(str(num_triangles), True, white)
        text_rect = text.get_rect(center=(center[0], center[1] + radius + 50))
        screen.blit(text, text_rect)

        pygame.display.flip()
        clock.tick(60)

main()
