import { defineConfig } from "vite";
import { createHtmlPlugin } from "vite-plugin-html";

export default defineConfig({
	base: "./",
	plugins: [
		createHtmlPlugin({
			pages: {
				index: {
					template: "public/index.html",
					filename: "index.html",
				},
				contato: {
					template: "public/contato.html",
					filename: "contato.html",
				},
				dicas: {
					template: "public/dicas.html",
					filename: "dicas.html",
				},
				futuros_projetos: {
					template: "public/futuros_projetos.html",
					filename: "futuros_projetos.html",
				},
				quem_somos: {
					template: "public/quem_somos.html",
					filename: "quem_somos.html",
				},
			},
		}),
	],
});
