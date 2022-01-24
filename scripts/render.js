/* Copyright 2022, Trail of Bits, Inc. All rights reserved. */

class TranslationUnit {
  constructor() {
    this.file_contents = {}
    this.main_file_id = null;
  }
};

async function render_translation_unit(obj) {

  const tu = new TranslationUnit;

  for (const file_id in obj.file_decls) {
    const source_file = 'sources/source.' + file_id + '.html';
    console.log("Downloading " + source_file);
    const response = await fetch(source_file);
    tu.file_contents[file_id] = await response.text();
  }

  tu.main_file_id = obj.file;
}
