//@region IMPORTS

//#endregion IMPORTS


//#region TEMPLATE
let template = document.createElement('template');
template.innerHTML = /*html*/ `
<link href="style.css" rel="stylesheet">
<div>
    <footer>
        <p>&copy; 2023 Remote Control Joystick. Kaj Vanreusel &amp Jens Achten</p>
    </footer>
</div>
    `;
//#endregion TEMPLATE

//#region CLASS
window.customElements.define('footer-a', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));
    }

    connectedCallback() {

    }
});