import { createDefaultPreset } from 'ts-jest';

const tsJestTransformCfg = createDefaultPreset().transform;

/** @type {import("jest").Config} **/
export const preset = 'ts-jest';
export const testEnvironment = 'node';
export const testMatch = ['**/src/**/*.test.ts', '**/src/**/*.spec.ts'];
export const moduleFileExtensions = ['ts', 'js', 'json', 'node'];
export const coveragePathIgnorePatterns = ['/node_modules/', '/dist/'];
export const setupFilesAfterEnv = [];
