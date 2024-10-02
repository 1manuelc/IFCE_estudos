pkg load image;
cd ./imgs/

img = imread('10.jpg'); % Carrega a imagem
img = im2double(img); % Converte os pixels da imagem ([0, 255]) para o intervalo [0, 1]

% Filtro 1: Efeito Noturno Leve
lut_r1 = linspace(0, 1, 256) * 0.22;
lut_g1 = linspace(0, 1, 256) * 0.18;
lut_b1 = linspace(0, 1, 256) * 0.38;

% Filtro 2: Efeito Noturno Profundo
lut_r2 = linspace(0, 1, 256) * 0.06;
lut_g2 = linspace(0, 1, 256) * 0.07;
lut_b2 = linspace(0, 1, 256) * 0.35;

% Filtro 3: Efeito Azul Intensificado
lut_r3 = linspace(0, 1, 256) * 0.08;
lut_g3 = linspace(0, 1, 256) * 0.10;
lut_b3 = linspace(0, 1, 256) * 0.45;

% Filtro Bônus: Efeito Solar
lut_r4 = linspace(0, 1, 256) * 1.3;
lut_g4 = linspace(0, 1, 256) * 1.1;
lut_b4 = linspace(0, 1, 256) * 0.9;

% Aplica os filtros na imagem
img_out1 = img;
img_out1(:,:,1) = lut_r1( round(img(:,:,1) * 255) + 1 );
img_out1(:,:,2) = lut_g1( round(img(:,:,2) * 255) + 1 );
img_out1(:,:,3) = lut_b1( round(img(:,:,3) * 255) + 1 );

img_out2 = img;
img_out2(:,:,1) = lut_r2( round(img(:,:,1) * 255) + 1 );
img_out2(:,:,2) = lut_g2( round(img(:,:,2) * 255) + 1 );
img_out2(:,:,3) = lut_b2( round(img(:,:,3) * 255) + 1 );

img_out3 = img;
img_out3(:,:,1) = lut_r3( round(img(:,:,1) * 255) + 1 );
img_out3(:,:,2) = lut_g3( round(img(:,:,2) * 255) + 1 );
img_out3(:,:,3) = lut_b3( round(img(:,:,3) * 255) + 1 );

img_out4 = img;
img_out4(:,:,1) = lut_r4( round(img(:,:,1) * 255) + 1 );
img_out4(:,:,2) = lut_g4( round(img(:,:,2) * 255) + 1 );
img_out4(:,:,3) = lut_b4( round(img(:,:,3) * 255) + 1 );

% Plotagem
figure;
subplot(2,3,1); imshow(img); title('Imagem Original');
subplot(2,3,2); imshow(img_out1); title('Efeito Noturno Leve');
subplot(2,3,3); imshow(img_out2); title('Efeito Noturno Profundo');
subplot(2,3,4); imshow(img_out3); title('Efeito Azul Intensificado');
subplot(2,3,5); imshow(img_out4); title('Efeito Solar');

% imshow(img); title('Imagem Original');
% imshow(img_out1); title('Efeito Noturno Leve');
% imshow(img_out2); title('Efeito Noturno Profundo');
% imshow(img_out3); title('Efeito Azul Intensificado');
% imshow(img_out4); title('Efeito Solar');

clear all
