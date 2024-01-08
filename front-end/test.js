//@region IMPORTS

//#endregion IMPORTS


//#region TEMPLATE
let template = document.createElement('template');
template.innerHTML = /*html*/ `
<link href="style.css" rel="stylesheet">
<body>
    <div>
      <h1>Testpagina</h1>
      <p>Op deze pagina kan je de instellingen testen.</p>
      <br>
      <svg height="450" width="1500">
        <ellipse cx="800" cy="150" rx="75" ry="75" fill="transparent" stroke="black" stroke-width="2" />
        <ellipse cx="800" cy="150" rx="20" ry="20" fill="blue" stroke="blue" stroke-width="2" id="joystick" />

        <ellipse cx="1100" cy="100" rx="20" ry="20" fill="transparent" stroke="black" stroke-width="2" id="boven"/>

        <ellipse cx="1050" cy="150" rx="20" ry="20" fill="transparent" stroke="black" stroke-width="2" id="links"/>
        <ellipse cx="1150" cy="150" rx="20" ry="20" fill="transparent" stroke="black" stroke-width="2" id="rechts"/>
        
        <ellipse cx="1100" cy="200" rx="20" ry="20" fill="transparent" stroke="black" stroke-width="2" id="onder"/>
    </svg>
    </div>
    
    
</body>
    `;
//#endregion TEMPLATE

//#region CLASS
window.customElements.define('test-a', class extends HTMLElement {
    constructor() {
        super();
        this._shadowRoot = this.attachShadow({ 'mode': 'open' });
        this._shadowRoot.appendChild(template.content.cloneNode(true));

        this.$joystick = this._shadowRoot.querySelector('#joystick');
        this.$boven = this._shadowRoot.querySelector('#boven');
        this.$links = this._shadowRoot.querySelector('#links');
        this.$rechts = this._shadowRoot.querySelector('#rechts');
        this.$onder = this._shadowRoot.querySelector('#onder');
    }

    connectedCallback() {
        this.$boven.addEventListener('mousedown', () => {
            this.$boven.style.fill = 'yellow';
        })
        this.$boven.addEventListener('mouseup', () => {
            this.$boven.style.fill = 'transparent';
        })

        this.$links.addEventListener('mousedown', () => {
            this.$links.style.fill = 'blue';
        })
        this.$links.addEventListener('mouseup', () => {
            this.$links.style.fill = 'transparent';
        })

        this.$rechts.addEventListener('mousedown', () => {
            this.$rechts.style.fill = 'red';
        })
        this.$rechts.addEventListener('mouseup', () => {
            this.$rechts.style.fill = 'transparent';
        })

        this.$onder.addEventListener('mousedown', () => {
            this.$onder.style.fill = 'green';
        })
        this.$onder.addEventListener('mouseup', () => {
            this.$onder.style.fill = 'transparent';
        })
    }
});