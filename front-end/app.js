//@region IMPORTS
import './navbar.js'
import './home.js'
import './test.js'
import './configuratie.js'
import './footer.js'
//#endregion IMPORTS


//#region TEMPLATE
let template = document.createElement('template');
template.innerHTML = /*html*/ `
<link rel="stylesheet" href="style.css">

    <div>
        <navbar-a></navbar-a>
        <footer-a></footer-a>
    </div>
    `;
//#endregion TEMPLATE

//#region CLASS
window.customElements.define('app-a', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));
    }

    connectedCallback() {

    }
});