// グルーコードの先頭に転記される

var Module = {
    preInit: [
        () => { console.log('preInit'); },
    ],
    locateFile: (path, scriptDirectory) =>
    {
        console.log(`locateFile('${path}','${scriptDirectory}')`);

        return scriptDirectory + path;
    },
    arguments: ['HELLO'],
};

// <<== extern-pre.js
