//Can be used for making production build using vite and react 
//Build (dist folder content) can directly be used for github pages hosting

import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react-swc';

const buildTimestamp = (() => {
  //Example: 05_12_2024_at_09-10
  const now = new Date();
  const yyyy = now.getFullYear();
  const mm = String(now.getMonth() + 1).padStart(2, '0');
  const dd = String(now.getDate()).padStart(2, '0');
  const hh = String(now.getHours()).padStart(2, '0');
  const min = String(now.getMinutes()).padStart(2, '0');
  return `${dd}_${mm}_${yyyy}_at_${hh}-${min}`;
})();

export default defineConfig({
  plugins: [react()],
  base: './',
  build: {
    outDir: `dist-${buildTimestamp}`,
    rollupOptions: {
      output: {
        entryFileNames: '[name]-[hash].js',
        chunkFileNames: '[name]-[hash].js',
        assetFileNames: (assetInfo) =>
          assetInfo.type === 'asset' && assetInfo.extname === '.css'
            ? '[name]-[hash].css'
            : '[name]-[hash][extname]',
      },
    },
  },
});
