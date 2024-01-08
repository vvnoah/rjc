//@region IMPORTS
import "./navbar.js"
import "./footer.js"
//#endregion IMPORTS


//#region TEMPLATE
let template = document.createElement('template');
template.innerHTML = /*html*/ `
<link href="style.css" rel="stylesheet">
<body>
    <div>
        <h1>Remote Control Joystick</h1>
        <p>Op deze site kan je de instellingen van de controller testen en aanpassen</p>
        <img src="img/controller.png" alt="controller" class="centerImage"/>
    </div>    
</body>
    `;
//#endregion TEMPLATE

//#region CLASS
window.customElements.define('home-a', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));


    }

    connectedCallback() {}
});