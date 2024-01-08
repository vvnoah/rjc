//@region IMPORTS
import './cursor.js'
import './keybind.js'
//#endregion IMPORTS


//#region TEMPLATE
let template = document.createElement('template');
template.innerHTML = /*html*/ `
<link href="style.css" rel="stylesheet">
<body>
    <div>
      <h1>Configuratie</h1>
      <p>Hier kan je de instellingen aanpassen.</p>
      <br>
      <cursor-k></cursor-k>
      <keybind-k></keybind-k>
      <keybind-k></keybind-k>
      <keybind-k></keybind-k>

    </div>
</body>
    `;
//#endregion TEMPLATE

//#region CLASS
window.customElements.define('config-a', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));


    }

    connectedCallback() {}
});