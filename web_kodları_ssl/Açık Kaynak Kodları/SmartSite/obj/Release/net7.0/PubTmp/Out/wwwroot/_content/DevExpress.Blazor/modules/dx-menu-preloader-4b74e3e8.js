import{defineDxCustomElement as e}from"./define-custom-element-ee3a9585.js";import{getDeviceInfo as t}from"./dx-blazor-54b4c45b.js";class d extends HTMLElement{constructor(){super()}static get observedAttributes(){return["menu-id"]}attributeChangedCallback(e,t,d){"menu-id"===e&&this.updateAttributes(d)}updateAttributes(e){const d=document.querySelector(`[data-dxmenu-id=${e}]`);if(d){t().isMobileDevice&&d.toggleAttribute("data-dx-menu-mobile",!0),d.toggleAttribute("data-dx-menu-loaded",!0)}}}e(customElements,"dxbl-menu-preloader",d);export{d as default};
