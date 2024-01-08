//@region IMPORTS
import './home.js'
//#endregion IMPORTS


//#region TEMPLATE
const template = document.createElement('template');
template.innerHTML = /*html*/ `
<link href="style.css" rel="stylesheet">
    <header>
        <div class="topnav">
            <button id="home">Home</button>
            <button id="test">Test</button>
            <button id="config">Configuratie</button>
        </div>
    </header>
    <body>
        <home-a id="homePage"></home-a>
        <test-a id="testPage"></test-a>
        <config-a id="configPage"></config-a>
    </body>
    `;
//#endregion TEMPLATE

//#region CLASS
window.customElements.define('navbar-a', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));

        this.$home = this._shadowRoot.querySelector('#home');
        this.$test = this._shadowRoot.querySelector('#test');
        this.$config = this._shadowRoot.querySelector('#config');

        this.$homePage = this._shadowRoot.querySelector('#homePage');
        this.$testPage = this._shadowRoot.querySelector('#testPage');
        this.$configPage = this._shadowRoot.querySelector('#configPage');
    }

    connectedCallback() {
        this.$testPage.style.display = 'none';
        this.$configPage.style.display = 'none';

        this.$home.addEventListener('click', () => {
            this.$homePage.style.display = 'block';
            this.$testPage.style.display = 'none';
            this.$configPage.style.display = 'none';
        })
        this.$test.addEventListener('click', () => {
            this.$homePage.style.display = 'none';
            this.$testPage.style.display = 'block';
            this.$configPage.style.display = 'none';
        })
        this.$config.addEventListener('click', () => {
            this.$homePage.style.display = 'none';
            this.$testPage.style.display = 'none';
            this.$configPage.style.display = 'block';
        })
    }
});