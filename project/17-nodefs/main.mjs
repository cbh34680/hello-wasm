import path from 'path';
import fs from 'fs';
import Module from './build/Debug/17_nodefs.js';

const inputFileName = 'data.txt'

const osTempDir = path.join(process.cwd(), 'os_tmp')
if (!fs.existsSync(osTempDir))
{
    // OS 上のディレクトリを作成
    fs.mkdirSync(osTempDir, { recursive: true });
}

// OS からみたフルパス
const osFullPath = path.join(`${osTempDir}`, inputFileName)

// 仮想ファイルシステムからみたパス
const esTempDir = '/es_tmp'
const esFullPath = `${esTempDir}/${inputFileName}`

console.log(`esFullPath=[${esFullPath}], osFullPath=[${osFullPath}]`)

const preRun = [emsModule => {
    const { FS, NODEFS } = emsModule
    FS.mkdir(esTempDir)

    // OS のディレクトリを仮想ファイルシステムにマウント
    FS.mount(NODEFS, { root: osTempDir }, esTempDir)

    const info = FS.analyzePath(esFullPath)
    if (info.exists)
    {
        // 現在のファイルの内容を表示
        const inStr = FS.readFile(esFullPath, {encoding: 'utf8'})
        console.log(inStr.trim())
    }

    // 現時刻を追加で書き込み
    const outStr = `JS:  ${(new Date()).toLocaleString()}\n`
    const outBin = new TextEncoder().encode(outStr)

    const stream = FS.open(esFullPath, 'a')
    FS.write(stream, outBin, 0, outBin.length)
    FS.close(stream);
}]

const emsModule = await Module({ arguments: [esFullPath], preRun })

console.log(`DONE`)

