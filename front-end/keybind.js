//#region IMPORTS
//#endregion IMPORTS

//#region TEMPLATE
let template = document.createElement('template');
template.innerHTML = /*html*/ `
<link href="style.css" rel="stylesheet">

    <div class="keybind">
    <label for="keyBindInputBox">Keybind:</label>

        <input type="text" id="keyBindInput" placeholder="Press a key to bind">
    </div>
    <br>
`;

//#endregion TEMPLATE

//#region CLASS
window.customElements.define('keybind-k', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));

        // Elementen selecteren
        this._keyBindInput = this._shadowRoot.getElementById('keyBindInput');

        // Key bindings instellen
        this._keyBindings = {};

        // Keydown event listener toevoegen voor het binden van toetsen
        this._keyBindInput.addEventListener('focus', () => this._startBinding());
    }

    connectedCallback() {
        console.log('configuratie-scherm is verbonden');
    }

    _startBinding() {
        // Voeg een event listener toe die wacht op een toetsaanslag
        const keyPressHandler = (event) => this._bindKey(event);

        // Voeg de event listener toe
        window.addEventListener('keydown', keyPressHandler, { once: true });

        // Verwijder de focus-event listener om dubbele binding te voorkomen
        this._keyBindInput.removeEventListener('focus', () => this._startBinding());
    }

    _bindKey(event) {
        // Voorkom dat de invoer van het tekstveld wordt bijgewerkt met de gedrukte toets
        event.preventDefault();

        // Bind de huidige toets aan de huidige snelheidsverandering
        const speedChange = 1; // Je kunt hier een vaste waarde gebruiken of je eigen logica toepassen
        this._keyBindings[event.key] = speedChange;

        // Update het tekstveld met de gebonden toets
        this._keyBindInput.value = event.key;

        // Blur het tekstveld om te voorkomen dat verdere tekstinvoer mogelijk is
        this._keyBindInput.blur();

        // Voeg de focus-event listener opnieuw toe voor verdere bindingen
        this._keyBindInput.addEventListener('focus', () => this._startBinding());

        // Verwijder de keydown event listener om te voorkomen dat dezelfde toets meerdere keren wordt gebonden
        window.removeEventListener('keydown', keyPressHandler);
    }
});
//#endregion CLASS