//@region IMPORTS
//#endregion IMPORTS

//#region TEMPLATE
let template = document.createElement('template');
template.innerHTML = /*html*/ `
<link href="style.css" rel="stylesheet">
    <div class="cursorBind">
        <label for="speedInput">Cursor Snelheid:</label>
        <input class="cursorBindInput" type="number" id="speedInput" value="50" min="1" max="100">
        <button id="increaseBtn">↑</button>
        <button id="decreaseBtn">↓</button>
    </div>
    <br>

`;

//#endregion TEMPLATE

//#region CLASS
window.customElements.define('cursor-k', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));

        // Elementen selecteren
        this._speedInput = this._shadowRoot.getElementById('speedInput');
        this._increaseBtn = this._shadowRoot.getElementById('increaseBtn');
        this._decreaseBtn = this._shadowRoot.getElementById('decreaseBtn');

        // Event listeners toevoegen
        this._increaseBtn.addEventListener('click', () => this._changeSpeed(1));
        this._decreaseBtn.addEventListener('click', () => this._changeSpeed(-1));
    }

    connectedCallback() {
        console.log('configuratie-scherm is verbonden');
    }


    _changeSpeed(change) {
        let currentSpeed = parseInt(this._speedInput.value, 10);
        let newSpeed = Math.max(1, Math.min(100, currentSpeed + change));
        this._speedInput.value = newSpeed;
        // Hier kun je extra logica toevoegen om de snelheid daadwerkelijk in te stellen
        console.log('Nieuwe snelheid:', newSpeed);
    }

});
//#endregion CLASS