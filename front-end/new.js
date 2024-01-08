//@region IMPORTS

//#endregion IMPORTS


//#region TEMPLATE
let template = document.createElement('template');
template.innerHTML = /*html*/ `
<link href="style.css" rel="stylesheet">

    <div>

    </div>
    `;
//#endregion TEMPLATE

//#region CLASS
window.customElements.define('new-a', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));
    }

    connectedCallback() {

    }
});