fetch('./build/Debug/11_compile_worker.wasm').then(response => {
    console.log('fetch done');
    WebAssembly.compileStreaming(response).then(wasmModule => {
        console.log('compile done')

        self.postMessage(wasmModule);
    });
});
